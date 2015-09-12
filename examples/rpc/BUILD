load("/third_party/grpc/grpc_proto", "proto_library")

proto_library(
  name = "bank",
  src = "bank.proto")

cc_binary(
  name = "bank_server",
  srcs = [
    "bank_server.cc"
  ],
  deps = [
    ":bank",
    "//third_party/glog",
    "//third_party/gflags"
  ]
)

cc_binary(
  name = "bank_client",
  srcs = [
    "bank_client.cc"
  ],
  deps = [
    ":bank",
    "//third_party/glog",
    "//third_party/gflags"
  ]
)
