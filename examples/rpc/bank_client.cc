#include "examples/rpc/bank.grpc.pb.h"

#include "gflags/gflags.h"
#include "glog/logging.h"

#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include <grpc++/support/status.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

DEFINE_int32(port, 10000, "Listening port of RPC service.");
DEFINE_double(deposit_amount, 25, "The amount to deposit.");

namespace examples {

static void RunClient() {
  LOG(INFO) << "Start the client.";
  std::shared_ptr<Channel>
    channel(grpc::CreateChannel("localhost:10000",
                                    grpc::InsecureCredentials()));
  std::unique_ptr<Bank::Stub> stub(Bank::NewStub(channel));
  DepositRequest request;
  request.set_account("dionescu");
  request.set_amount(FLAGS_deposit_amount);
  ClientContext context;
  DepositReply response;
  Status status = stub->Deposit(&context, request, &response);
  if (status.ok()) {
    LOG(INFO) << response.account() << " balance:" << response.balance();
  } else {
    LOG(INFO) << "Rpc failed";
  }
}

}  // namespace examples

int main(int argc, char** argv) {
  google::InstallFailureSignalHandler();
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);
  grpc_init();
  examples::RunClient();

  grpc_shutdown();
  return 0;
}
