#include "cpr/cpr.h"
#include "src/protos/tpa.grpc.pb.h"

namespace tba {
namespace models {
tpa::Team json_to_team(std::string json) {
  tpa::Team team;
  team.set_key(json);
  return team;
}
}  // namespace models

tpa::Team team(std::string team, bool simple = false) {
  return models::json_to_team(team);
}

}  // namespace tba
