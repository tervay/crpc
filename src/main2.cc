#include <iostream>
#include <string>
#include <vector>

#include "tba/tba.h"

int main() {
  // auto req = make_request("team/frc2713");
  // std::cout << req.text << std::endl;

  auto t = tba::team("frc2713");

  std::cout << t.DebugString() << "\n";
}