#include "src/protos/tpa.grpc.pb.h"

namespace tba {

tpa::Team team(std::string team);
std::vector<tpa::Team> teams(int year);
tpa::Event event(std::string event_key);

}  // namespace tba
