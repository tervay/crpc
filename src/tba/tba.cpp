#include "absl/status/statusor.h"
#include "absl/strings/str_format.h"
#include "cpr/cpr.h"
#include "src/include/json/json.hpp"
#include "src/protos/tpa.grpc.pb.h"

using JSON = nlohmann::json;

#define SET_IF_NOT_NULL(message, message_field, json, json_field) \
  {                                                               \
    if (!json[json_field].is_null()) {                            \
      (message).set_##message_field(json[json_field]);            \
    }                                                             \
  }

const std::string TBA_URL = "https://www.thebluealliance.com/api/v3";
const std::string TBA_KEY =
    "FfBdTrj0DX7qOqbIaLYYQ0i5HemtJYC2S6OlYl12ODrFdjdpMwG176m0zcL2Jtwn";

namespace tba {
namespace net {
std::string make_url(std::string endpoint) {
  std::cout << absl::StrFormat("%s/%s", TBA_URL, endpoint) << std::endl;
  return absl::StrFormat("%s/%s", TBA_URL, endpoint);
}

absl::StatusOr<JSON> make_request(std::string endpoint) {
  auto response = cpr::Get(cpr::Url(make_url(endpoint)),
                           cpr::Header{{"X-TBA-Auth-Key", TBA_KEY}});
  if (response.status_code == 200) {
    return JSON::parse(response.text);
  }

  return absl::UnknownError(response.text);
}
}  // namespace net

namespace models {
tpa::Location json_to_location(JSON json) {
  tpa::Location loc;

  SET_IF_NOT_NULL(loc, city, json, "city");
  SET_IF_NOT_NULL(loc, state_prov, json, "state_prov");
  SET_IF_NOT_NULL(loc, country, json, "country");
  SET_IF_NOT_NULL(loc, postal_code, json, "postal_code");

  return loc;
}
tpa::Team json_to_team(JSON json) {
  tpa::Team team;

  SET_IF_NOT_NULL(team, key, json, "key");
  SET_IF_NOT_NULL(team, team_number, json, "team_number");
  SET_IF_NOT_NULL(team, name, json, "name");
  SET_IF_NOT_NULL(team, nickname, json, "nickname");
  SET_IF_NOT_NULL(team, school_name, json, "school_name");
  SET_IF_NOT_NULL(team, website, json, "website");
  SET_IF_NOT_NULL(team, rookie_year, json, "rookie_year");

  *team.mutable_location() = json_to_location(json);

  return team;
}
std::vector<tpa::Team> json_to_teams(JSON json) {
  std::vector<tpa::Team> teams;
  teams.reserve(json.size());
  for (auto& el : json) {
    teams.push_back(json_to_team(el));
    }
  return teams;
}
tpa::Event json_to_event(JSON json) {
  tpa::Event event;

  SET_IF_NOT_NULL(event, key, json, "key");
  SET_IF_NOT_NULL(event, name, json, "name");
  SET_IF_NOT_NULL(event, event_code, json, "event_code");
  SET_IF_NOT_NULL(event, event_type, json, "event_type");
  SET_IF_NOT_NULL(event, start_date, json, "start_date");
  SET_IF_NOT_NULL(event, end_date, json, "end_date");
  SET_IF_NOT_NULL(event, year, json, "year");
  SET_IF_NOT_NULL(event, short_name, json, "short_name");
  SET_IF_NOT_NULL(event, event_type_string, json, "event_type_string");
  SET_IF_NOT_NULL(event, week, json, "week");
  SET_IF_NOT_NULL(event, website, json, "website");
  SET_IF_NOT_NULL(event, first_event_id, json, "first_event_id");
  SET_IF_NOT_NULL(event, first_event_code, json, "first_event_code");
  SET_IF_NOT_NULL(event, parent_event_key, json, "parent_event_key");
  SET_IF_NOT_NULL(event, playoff_type, json, "playoff_type");
  SET_IF_NOT_NULL(event, playoff_type_string, json, "playoff_type_string");

  for (auto& el : json["webcasts"]) {
    tpa::Webcast* wc = event.add_webcasts();
    SET_IF_NOT_NULL(*wc, type, el, "type");
    SET_IF_NOT_NULL(*wc, channel, el, "channel");
    SET_IF_NOT_NULL(*wc, date, el, "date");
    SET_IF_NOT_NULL(*wc, file, el, "file");
  }

  return event;
}
}  // namespace models

tpa::Team team(std::string team) {
  absl::StatusOr<JSON> json =
      net::make_request(absl::StrFormat("team/%s", team));
  return models::json_to_team(json.value());
}

std::vector<tpa::Team> teams(int year) {
  int page = 0;
  std::vector<tpa::Team> teams;
  do {
    absl::StatusOr<JSON> json =
        net::make_request(absl::StrFormat("teams/%d/%d", year, page));
    if (!json.ok() || json.value().size() == 0) {
      break;
    }

    auto paged_teams = models::json_to_teams(json.value());
    teams.reserve(paged_teams.size());
    teams.insert(teams.end(), paged_teams.begin(), paged_teams.end());

    page += 1;
  } while (true);

  return teams;
}

tpa::Event event(std::string event_key) {
  absl::StatusOr<JSON> json =
      net::make_request(absl::StrFormat("event/%s", event_key));
  return models::json_to_event(json.value());
}

}  // namespace tba
