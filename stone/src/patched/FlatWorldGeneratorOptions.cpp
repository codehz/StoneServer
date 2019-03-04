#include "../patched.h"

#include <mcpelauncher/path_helper.h>
#include <minecraft/json.h>
#include <stone/server_hook.h>

#include <fstream>

namespace {

SHook(Json::Value &, _ZN25FlatWorldGeneratorOptions10getDefaultEv) {
  auto &ret = original();
  Json::Reader reader;
  auto path = PathHelper::getPrimaryDataDirectory() + "flat_world_generator.json";
  std::ifstream ifs(path);
  if (!ifs) {
    Json::StyledWriter writer;
    std::ofstream ofs(path);
    ofs << writer.write(ret);
    return ret;
  }
  reader.parse(ifs, ret, false);
  return ret;
}

} // namespace