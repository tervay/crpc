#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_format.h"
#include "cpr/cpr.h"
#include "tba/tba.h"

const std::string TBA_URL = "https://www.thebluealliance.com/api/v3";
const std::string TBA_KEY =
    "FfBdTrj0DX7qOqbIaLYYQ0i5HemtJYC2S6OlYl12ODrFdjdpMwG176m0zcL2Jtwn";

std::string make_url(std::string endpoint) {
  return absl::StrFormat("%s/%s", TBA_URL, endpoint);
}

cpr::Response make_request(std::string endpoint) {
  return cpr::Get(cpr::Url{make_url(endpoint)},
                  cpr::Header{{"X-TBA-Auth-Key", TBA_KEY}});
}

int main() {
  auto req = make_request("team/frc2713");
  std::cout << req.text << std::endl;
}