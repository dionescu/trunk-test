licenses(["notice"])

AM_CXXFLAGS = [
  # Include the headers.
  "-Ithird_party/benchmark/upstream/include",
  "-Wall",
  "-Wextra",
  "-Wshadow",
  "-Werror",
  "-pedantic",
  "-pedantic-errors",
  "-Wfloat-equal",
  "-Wzero-as-null-pointer-constant",
  "-fstrict-aliasing",
  "-Wstrict-aliasing",
]

cc_library(
  visibility = ["//visibility:public"],
  name = "benchmark",
  copts = AM_CXXFLAGS,
  linkopts = [
    "-pthread",
  ],
  srcs = [
    "upstream/src/benchmark.cc",
    "upstream/src/colorprint.cc",
    "upstream/src/commandlineflags.cc",
    "upstream/src/console_reporter.cc",
    "upstream/src/csv_reporter.cc",
    "upstream/src/json_reporter.cc",
    "upstream/src/log.cc",
    "upstream/src/re_posix.cc",
    "upstream/src/reporter.cc",
    "upstream/src/sleep.cc",
    "upstream/src/string_util.cc",
    "upstream/src/sysinfo.cc",
    "upstream/src/walltime.cc"
  ],
  hdrs = [
    "upstream/src/arraysize.h",
    "upstream/src/check.h",
    "upstream/src/colorprint.h",
    "upstream/src/commandlineflags.h",
    "upstream/src/cycleclock.h",
    "upstream/src/internal_macros.h",
    "upstream/src/log.h",
    "upstream/src/mutex.h",
    "upstream/src/re.h",
    "upstream/src/sleep.h",
    "upstream/src/stat.h",
    "upstream/src/string_util.h",
    "upstream/src/sysinfo.h",
    "upstream/src/walltime.h"	
  ],
  includes = [
    "upstream/include",
  ],
  defines = ["HAVE_POSIX_REGEX"],
)

cc_test(
  name = "basic_test",
  srcs = ["upstream/test/basic_test.cc"],
  deps = [
    ":benchmark",
  ]
)

cc_test(
  name = "benchmark_test",
  srcs = ["upstream/test/benchmark_test.cc"],
  deps = [
    ":benchmark",
  ]
)
  
