#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct apid_method_reply_ctx apid_method_reply_ctx;
typedef void (*apid_zero_callback)(void *privdata);
typedef void (*apid_data_callback)(char const *data, void *privdata);
typedef void (*apid_data2_callback)(char const *identify, char const *data, void *privdata);
typedef void (*apid_action_callback)(char const *);
typedef void (*apid_method_callback)(char const *, apid_method_reply_ctx *);

int apid_init();
int apid_init_unix(char const *path);
int apid_init_tcp(char const *ip, int port);
int apid_start();
int apid_stop();

int apid_register_action(char const *name, apid_action_callback callback);
int apid_register_method(char const *name, apid_method_callback callback);
int apid_method_reply(apid_method_reply_ctx *, char const *content);

int apid_invoke(apid_zero_callback callback, void *privdata, char const *name, char const *argument);
int apid_invoke_method(apid_data_callback callback, void *privdata, char const *name, char const *argument);

int apid_set_prop(apid_zero_callback callback, void *privdata, char const *name, char const *value);
int apid_get_prop(apid_data_callback callback, void *privdata, char const *name);

int apid_publish(char const *name, char const *data);
int apid_subscribe(apid_data_callback callback, void *privdata, char const *name, char const *data);
int apid_subscribe_pattern(apid_data2_callback callback, void *privdata, char const *pattern, char const *data);

#ifdef __cplusplus
}
#endif