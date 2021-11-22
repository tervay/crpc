#include <google/protobuf/util/json_util.h>

#include "absl/status/statusor.h"
#include "absl/strings/str_format.h"
#include "cpr/cpr.h"
#include "src/include/json/json.hpp"
#include "src/protos/tpa.grpc.pb.h"

using JSON = nlohmann::json;

const std::string TBA_URL = "https://www.thebluealliance.com/api/v3";
const std::string TBA_KEY =
    "FfBdTrj0DX7qOqbIaLYYQ0i5HemtJYC2S6OlYl12ODrFdjdpMwG176m0zcL2Jtwn";

namespace tba {
namespace net {
std::string make_url(std::string endpoint) {
  std::cout << absl::StrFormat("%s/%s", TBA_URL, endpoint) << std::endl;
  return absl::StrFormat("%s/%s", TBA_URL, endpoint);
}

absl::StatusOr<std::string> make_request(std::string endpoint) {
  auto response = cpr::Get(cpr::Url(make_url(endpoint)),
                           cpr::Header{{"X-TBA-Auth-Key", TBA_KEY}});
  if (response.status_code == 200) {
    // return JSON::parse(response.text);
    return response.text;
  }

  return absl::UnknownError(response.text);
}
}  // namespace net

namespace models {
tpa::Team json_to_team(JSON json) {
  tpa::Team team;
  google::protobuf::util::JsonStringToMessage(json, &team);

  return team;
}
}  // namespace models

tpa::Team team(std::string team, bool simple = false) {
  auto json = net::make_request(
      absl::StrFormat("team/%s%s", team, simple ? "/simple" : ""));
  if (!json.ok()) {
    // return json.status();
  }

  return models::json_to_team(json.value());
}

}  // namespace tba
