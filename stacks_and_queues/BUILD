load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "stacks_and_queues",
    srcs = glob(
        ["*.cc"],
        exclude = ["*_test.cc"],
    ),
    hdrs = glob(["*.h"]),
    visibility = ["//main:__pkg__"],
    deps = ["//lib"],
)

cc_test(
    name = "tests",
    srcs = glob(["*_test.cc"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        ":stacks_and_queues",
        "@googletest//:gtest_main",
    ],
)