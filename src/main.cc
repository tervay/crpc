#include <memory>

#include <google/protobuf/text_format.h>
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include <iostream>
#include <src/protos/tba.grpc.pb.h>

int main(int argc, char *argv[]) {
  std::shared_ptr<grpc::Channel> channel =
      grpc::CreateChannel("localhost:1337", grpc::InsecureChannelCredentials());
  std::unique_ptr<tpa::TPA::Stub> stub = tpa::TPA::NewStub(channel);
  grpc::ClientContext context;
  tpa::TeamKey key;
  key.set_team_key("frc2791");
  tpa::Team team;
  grpc::Status status = stub->getTeam(&context, key, &team);

  if (!status.ok()) {
    std::cerr << status.error_details();
    std::cerr << status.error_message();
  } else {
    std::string s;
    google::protobuf::TextFormat::PrintToString(team, &s);
    std::cout << s;
  }
}