#include <apid.h>
#include <assert.h>
#include <stdio.h>

static void test1(char const *inp) { printf("recv1: %s\n", inp); }
static void test2(char const *inp, apid_method_reply_ctx *reply) {
  printf("recv2: %s\n", inp);
  apid_method_reply(reply, inp);
}

int main() {
  assert(apid_init() == 0);
  apid_register_action("test1", test1);
  apid_register_method("test2", test2);
  apid_set_prop(NULL, NULL, "note", "it is the note!");
  apid_start();
}