#include "apid.h"

#include <malloc.h>

#include <adapters/ae.h>
#include <assert.h>
#include <async.h>
#include <hiredis.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

static aeEventLoop *loop          = NULL;
static redisAsyncContext *sub_ctx = NULL;
static redisAsyncContext *ctx     = NULL;

static void rand_str(char *dest, size_t length) {
  char charset[] =
      "0123456789"
      "abcdefghijklmnopqrstuvwxyz"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  while (length-- > 0) {
    size_t index = (double)rand() / RAND_MAX * (sizeof charset - 1);
    *dest++      = charset[index];
  }
  *dest = '\0';
}

static void connectCallback(const redisAsyncContext *c, int status) {
  if (status != REDIS_OK) {
    printf("Error: %s\n", c->errstr);
    aeStop(loop);
    return;
  }
}

static void disconnectCallback(const redisAsyncContext *c, int status) {
  if (status != REDIS_OK) {
    printf("Error: %s\n", c->errstr);
    aeStop(loop);
    return;
  }
  aeStop(loop);
}

static void check_error(redisAsyncContext *c, void *r, void *privdata) {
  if (c->err) {
    printf("%s: %s\n", privdata, c->errstr);
    exit(1);
  }
}

static int post_init() {
  if (sub_ctx->err) {
    printf("Error: %s\n", sub_ctx->errstr);
    return 1;
  }
  if (ctx->err) {
    printf("Error: %s\n", sub_ctx->errstr);
    return 1;
  }
  redisAsyncSetConnectCallback(sub_ctx, connectCallback);
  redisAsyncSetDisconnectCallback(sub_ctx, disconnectCallback);
  redisAsyncSetConnectCallback(ctx, connectCallback);
  redisAsyncSetDisconnectCallback(ctx, disconnectCallback);
  loop = aeCreateEventLoop(64);
  redisAeAttach(loop, sub_ctx);
  redisAeAttach(loop, ctx);
  srand(time(0));
  return 0;
}

int apid_init_unix(char const *path) {
  sub_ctx = redisAsyncConnectUnix(path);
  ctx     = redisAsyncConnectUnix(path);
  return post_init();
}

int apid_init_tcp(char const *ip, int port) {
  sub_ctx = redisAsyncConnect(ip, port);
  ctx     = redisAsyncConnect(ip, port);
  return post_init();
}

int apid_init() {
  char const *addr = getenv("APID") ?: "unix:/tmp/apid.socket";
  if (strncmp(addr, "unix:", 5) == 0) {
    return apid_init_unix(addr + 5);
  } else if (strncmp(addr, "tcp:", 4) == 0) {
    char const *part = addr + 4;
    char const *port = strchr(part, ':');
    if (!port) return -1;
    char buffer[0x100] = { 0 };
    strncpy(buffer, part, port - part);
    return apid_init_tcp(buffer, atoi(port + 1));
  }
  return -2;
}

int apid_start() {
  if (loop)
    aeMain(loop);
  else
    return -1;
  return 0;
}

int apid_stop() {
  if (loop)
    aeStop(loop);
  else
    return -1;
  return 0;
}

static void action_callback_stub(redisAsyncContext *c, void *r, void *privdata) {
  apid_action_callback callback = privdata;
  redisReply *reply             = r;
  if (c->err) {
    printf("apid_register_action: %s\n", c->errstr);
    exit(1);
  }
  if (!reply || reply->type != REDIS_REPLY_ARRAY || strcmp(reply->element[0]->str, "message") != 0) return;
  callback(reply->element[2]->str);
}

int apid_register_action(char const *name, apid_action_callback callback) {
  return redisAsyncCommand(sub_ctx, action_callback_stub, callback, "SUBSCRIBE %s", name);
}

struct apid_method_reply_ctx {
  char buffer[0];
};

static void method_callback_stub(redisAsyncContext *c, void *r, void *privdata) {
  apid_method_callback callback = privdata;
  redisReply *reply             = r;
  if (c->err) {
    printf("apid_register_method: %s\n", c->errstr);
    exit(1);
  }
  if (!reply || reply->type != REDIS_REPLY_ARRAY || strcmp(reply->element[0]->str, "psubscribe") == 0) return;
  char *full                       = reply->element[2]->str;
  int len                          = strlen(full);
  apid_method_reply_ctx *reply_ctx = malloc(len);
  memcpy(reply_ctx, full, len);
  callback(reply->element[3]->str, reply_ctx);
}

int apid_register_method(char const *name, apid_method_callback callback) {
  return redisAsyncCommand(sub_ctx, method_callback_stub, callback, "PSUBSCRIBE %s@*", name);
}

int apid_method_reply(apid_method_reply_ctx *reply, char const *content) {
  int ret = redisAsyncCommand(ctx, NULL, NULL, "LPUSH %s %s", reply->buffer, content);
  free(reply);
  return ret;
}

typedef struct callback_bundle {
  void *callback;
  void *privdata;
} callback_bundle;

static void apid_zero_stub(redisAsyncContext *c, void *r, void *privdata) {
  callback_bundle *priv       = privdata;
  apid_zero_callback callback = priv->callback;
  void *userdata              = priv->privdata;
  redisReply *reply           = r;
  if (c->err) {
    printf("apid_zero_stub: %s\n", c->errstr);
    exit(1);
  }
  free(priv);
  callback(userdata);
}

int apid_invoke(apid_zero_callback callback, void *privdata, char const *name, char const *argument) {
  if (callback) {
    callback_bundle *priv = malloc(sizeof(callback_bundle));
    priv->callback        = callback;
    priv->privdata        = privdata;
    return redisAsyncCommand(ctx, apid_zero_stub, priv, "PUBLISH %s %s", name, argument);
  }
  return redisAsyncCommand(ctx, check_error, "apid_invoke", "PUBLISH %s %s", name, argument);
}

static void apid_invoke_method_stub(redisAsyncContext *c, void *r, void *privdata) {
  callback_bundle *priv = privdata;
  redisReply *reply     = r;
  if (c->err) {
    printf("apid_invoke_method_stub: %s\n", c->errstr);
    exit(1);
  }
  if (!reply) return;
  if (reply->type == REDIS_REPLY_STRING) {
    printf("apid_invoke_method_stub: %s\n", reply->str);
    exit(1);
  }
  if (reply->type != REDIS_REPLY_ARRAY) return;
  apid_data_callback callback = priv->callback;
  void *userdata              = priv->privdata;
  free(priv);
  callback(reply->element[1]->str, userdata);
}

int apid_invoke_method(apid_data_callback callback, void *privdata, char const *name, char const *argument) {
  if (callback) {
    callback_bundle *priv = malloc(sizeof(callback_bundle));
    priv->callback        = callback;
    priv->privdata        = privdata;
    char unq[0x10];
    rand_str(unq, 0x10);
    int ret = redisAsyncCommand(ctx, check_error, "apid_invoke_method", "PUBLISH %s@%s %s", name, unq, argument);
    ret |= redisAsyncCommand(ctx, apid_invoke_method_stub, priv, "BRPOP %s@%s 0", name, unq);
    return ret;
  }
  int ret = redisAsyncCommand(ctx, check_error, "apid_invoke_method", "PUBLISH %s@%ignore %s", name, argument);
  ret |= redisAsyncCommand(ctx, check_error, "apid_invoke_method", "BRPOP %s@ignore 0", name);
  return ret;
}

int apid_set_prop(apid_zero_callback callback, void *privdata, char const *name, char const *value) {
  if (callback) {
    callback_bundle *priv = malloc(sizeof(callback_bundle));
    priv->callback        = callback;
    priv->privdata        = privdata;
    return redisAsyncCommand(ctx, apid_zero_stub, priv, "SET %s %s", name, value);
  }
  return redisAsyncCommand(ctx, check_error, "apid_set_prop", "SET %s %s", name, value);
}

static void apid_data_stub(redisAsyncContext *c, void *r, void *privdata) {
  callback_bundle *priv = privdata;
  redisReply *reply     = r;
  if (c->err) {
    printf("apid_data_stub: %s\n", c->errstr);
    exit(1);
  }
  if (!reply) return;
  if (reply->type != REDIS_REPLY_STRING) return;
  apid_data_callback callback = priv->callback;
  void *userdata              = priv->privdata;
  free(priv);
  callback(reply->str, userdata);
}

int apid_get_prop(apid_data_callback callback, void *privdata, char const *name) {
  if (callback) {
    callback_bundle *priv = malloc(sizeof(callback_bundle));
    priv->callback        = callback;
    priv->privdata        = privdata;
    return redisAsyncCommand(ctx, apid_data_stub, priv, "GET %s", name);
  }
  return redisAsyncCommand(ctx, check_error, "apid_get_prop", "GET %s", name);
}

int apid_publish(char const *name, char const *data) { return redisAsyncCommand(ctx, check_error, "apid_publish", "PUBLISH %s %s", name, data); }

static void apid_subscibe_stub(redisAsyncContext *c, void *r, void *privdata) {
  callback_bundle *priv = privdata;
  redisReply *reply     = r;
  if (c->err) {
    printf("apid_subscribe: %s\n", c->errstr);
    exit(1);
  }
  if (!reply || reply->type != REDIS_REPLY_ARRAY || strcmp(reply->element[0]->str, "message") != 0) return;
  apid_data_callback callback = priv->callback;
  void *userdata              = priv->privdata;
  free(priv);
  callback(reply->str, userdata);
}

int apid_subscribe(apid_data_callback callback, void *privdata, char const *name, char const *data) {
  assert(callback);
  callback_bundle *priv = malloc(sizeof(callback_bundle));
  priv->callback        = callback;
  priv->privdata        = privdata;
  return redisAsyncCommand(sub_ctx, apid_subscibe_stub, priv, "SUBSCRIBE %s", name);
}

static void apid_subscibe_pattern_stub(redisAsyncContext *c, void *r, void *privdata) {
  callback_bundle *priv = privdata;
  redisReply *reply     = r;
  if (c->err) {
    printf("apid_register_method: %s\n", c->errstr);
    exit(1);
  }
  if (!reply || reply->type != REDIS_REPLY_ARRAY || strcmp(reply->element[0]->str, "psubscribe") == 0) return;
  apid_data2_callback callback = priv->callback;
  void *userdata               = priv->privdata;
  free(priv);
  callback(reply->element[2]->str, reply->element[3]->str, userdata);
}

int apid_subscribe_pattern(apid_data2_callback callback, void *privdata, char const *pattern, char const *data) {
  assert(callback);
  callback_bundle *priv = malloc(sizeof(callback_bundle));
  priv->callback        = callback;
  priv->privdata        = privdata;
  return redisAsyncCommand(sub_ctx, apid_subscibe_stub, priv, "PSUBSCRIBE %s", pattern);
}