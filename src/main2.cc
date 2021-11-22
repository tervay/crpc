#include <google/protobuf/util/json_util.h>

#include <iostream>
#include <string>
#include <vector>

#include "tba/tba.h"

int main() {
  // auto req = make_request("team/frc2713");
  // std::cout << req.text << std::endl;

  auto teams = tba::teams(2019);
  for (const auto& t : teams) {
    std::cout << t.key() << "\n";
  }
}