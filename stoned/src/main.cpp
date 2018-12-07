#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <csignal>

#include <seasocks/PrintfLogger.h>
#include <seasocks/Server.h>

#include <memory>

int main() {
  using namespace seasocks;
  auto logger = std::make_shared<PrintfLogger>();
  Server server(logger);
  server.serve("web", 9090);
}