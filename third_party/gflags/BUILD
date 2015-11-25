licenses(["notice"])

cc_library(
  name = "gflags",
  visibility = ["//visibility:public"],
  includes = [
    "build/k8/include",
  ],
  srcs = [
    "upstream/src/gflags.cc",
    "upstream/src/gflags_completions.cc",
    "upstream/src/gflags_reporting.cc",
    "upstream/src/util.h",
    "upstream/src/mutex.h",
    "build/k8/include/gflags/config.h",
  ],
  hdrs = [
    "build/k8/include/gflags/gflags.h",
    "build/k8/include/gflags/gflags_completions.h",
    "build/k8/include/gflags/gflags_declare.h",
    "build/k8/include/gflags/gflags_gflags.h",
  ],
  copts = [
    "-Ithird_party/gflags/build/k8/include/gflags",
    "-Wno-sign-compare",
    "-Wno-unused-local-typedefs",
  ],
  linkopts = [
    "-pthread",
  ],
)

cc_test(
  name = "gflags_unittest",
  srcs = [
    "upstream/test/gflags_unittest.cc",
    "upstream/test/config_for_unittests.h",
  ],
  copts = [
    "-Ithird_party/gflags/build/k8/include/gflags",
    "-Ithird_party/gflags/upstream/src",
  ],
  deps = [
    ":gflags"
  ],
  data = [
    "upstream/test/gflags_unittest_flagfile",
  ],
  args = ["--srcdir=third_party/gflags"],
)
