#include "glog/logging.h"
#include "gflags/gflags.h"

DECLARE_bool(logtostderr);
DEFINE_string(username, "user", "The name of the user we salute.");

int main(int argc, char *argv[]) {
  FLAGS_logtostderr = true;
  google::InstallFailureSignalHandler();
  google::SetUsageMessage("hello");
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);
  LOG(INFO) << "Hello " << FLAGS_username << "!";
  return 0;
}
