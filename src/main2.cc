#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_format.h"
#include "include/HTTPRequest.hpp"

const std::string TBA_URL = "https://www.thebluealliance.com/api/v3";
const std::string TBA_KEY =
    "FfBdTrj0DX7qOqbIaLYYQ0i5HemtJYC2S6OlYl12ODrFdjdpMwG176m0zcL2Jtwn";

std::string make_url(std::string endpoint) {
  return absl::StrFormat("%s/%s", TBA_URL, endpoint);
}

http::Request make_request(std::string endpoint) {
  http::Request req(make_url(endpoint));
  return req;
}

int main() {
  auto req = make_request("team/frc2713");
  const auto response = req.send("GET");
  std::cout << std::string{response.body.begin(), response.body.end()}
            << '\n'; // print the result
}