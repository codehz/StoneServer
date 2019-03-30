#include <stone-api/Blacklist.h>
#include <stone-api/Core.h>

#include <iostream>

int main() {
  using namespace api;
  apid_init();

  BlacklistService<ClientSide> blacklist;
  blacklist.add(BlacklistOP<true>{ "xuid", "2131231231", "boom" });
  blacklist.add(BlacklistOP<true>{ "xuid", "5465456453", "boom" });
  blacklist.add(BlacklistOP<true>{ "xuid", "3464564564", "boom" });
  blacklist.add(BlacklistOP<true>{ "xuid", "2344546543", "boom" });
  blacklist.add(BlacklistOP<true>{ "xuid", "5465756734", "boom" });
  blacklist.add(BlacklistOP<true>{ "xuid", "2342355667", "boom" });
  blacklist.fetch({}, [](std::vector<BlacklistOP<true>> const &result) {
    std::cout << result.size() << std::endl;
    for (auto &item : result) { std::cout << item.type << std::endl << item.content << std::endl << item.reason << std::endl; }
  });

  apid_start();
}