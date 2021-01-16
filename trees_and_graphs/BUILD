load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "trees_and_graphs",
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
        ":trees_and_graphs",
        "@googletest//:gtest_main",
    ],
)
