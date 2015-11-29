licenses(["notice"])

cc_library(
  visibility = ["//visibility:public"],
  name = "glog",
  deps = [
    "//third_party/libunwind:libunwind-k8",
    "//third_party/gflags:gflags",
  ],
  includes = [
    "build/k8/include",
  ],
  copts = [
    "-DNO_FRAME_POINTER",
    "-fno-sanitize=thread",
    "-fno-sanitize=address",
    "-Wno-sign-compare",
    "-Ithird_party/glog/build/k8/src",
    "-Ithird_party/glog/upstream/src",
  ],
  srcs = [
    "upstream/src/demangle.cc",
    "upstream/src/logging.cc",
    "upstream/src/raw_logging.cc",
    "upstream/src/signalhandler.cc",
    "upstream/src/symbolize.cc",
    "upstream/src/utilities.cc",
    "upstream/src/vlog_is_on.cc",
    "upstream/src/demangle.h",
    "upstream/src/stacktrace.h",
    "upstream/src/stacktrace_libunwind-inl.h",
    "upstream/src/symbolize.h",
    "upstream/src/utilities.h",
    "upstream/src/base/commandlineflags.h",
    "upstream/src/base/googleinit.h",
    "upstream/src/base/mutex.h",
    "build/k8/src/config.h",
  ],
  hdrs = [
    "build/k8/include/glog/logging.h",
    "build/k8/include/glog/log_severity.h",
    "build/k8/include/glog/raw_logging.h",
    "build/k8/include/glog/vlog_is_on.h",
  ],
  linkopts = [
    "-pthread"
  ],
)

cc_test(
  name = "demangle_unittest",
  deps = [
    ":glog",
  ],
  srcs = [
    "upstream/src/demangle_unittest.cc",
    "upstream/src/googletest.h",
  ],
  data = [
    "upstream/src/demangle_unittest.txt",
  ],
  copts = [
    "-Ithird_party/glog/build/k8/src"
  ],
)

cc_test(
  name = "logging_unittest",
  deps = [
    ":glog",
  ],
  srcs = [
    "upstream/src/logging_unittest.cc",
    "upstream/src/googletest.h",
    "upstream/src/config_for_unittests.h",
  ],
  data = [
    "upstream/src/logging_unittest.err"
  ],
  copts = [
    "-Ithird_party/glog/build/k8/src"
  ],
)

cc_test(
  name = "symbolize_unittest",
  deps = [
    ":glog",
  ],
  srcs = [
    "upstream/src/symbolize_unittest.cc",
    "upstream/src/googletest.h",
  ],
  copts = [
    "-Ithird_party/glog/build/k8/src"
  ],
)

