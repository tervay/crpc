#include "cpr/cpr.h"
#include "src/include/json/json.hpp"
#include "src/protos/tpa.grpc.pb.h"

using JSON = nlohmann::json;

namespace tba {
namespace models {
JSON parse_json(std::string json) { return JSON::parse(json); }

tpa::Team json_to_team(JSON json) {
  tpa::Team team;
  team.set_key(json);
  return team;
}
}  // namespace models

tpa::Team team(std::string team, bool simple = false) {
  return models::json_to_team(team);
}

}  // namespace tba
