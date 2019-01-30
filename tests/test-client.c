#include <apid.h>
#include <assert.h>
#include <stdio.h>

void method_callback(char const *reply, void *priv) {
  printf("Got reply: %s\n", reply);
  apid_stop();
}

void prop_callback(char const *reply, void *priv) {
  printf("Got note: %s\n", reply);
}


int main() {
  assert(apid_init() == 0);
  apid_get_prop(prop_callback, NULL, "note");
  apid_invoke(NULL, NULL, "test1", "test from client");
  apid_invoke_method(method_callback, NULL, "test2", "test2 from client");
  apid_start();
}