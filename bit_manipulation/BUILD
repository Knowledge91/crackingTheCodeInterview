load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "bit_manipulation",
    srcs = glob(
        ["*.cc"],
        exclude = ["*_test.cc"],
    ),
    hdrs = glob(["*.h"]),
    visibility = ["//main:__pkg__"],
)

cc_test(
    name = "tests",
    srcs = glob(["*_test.cc"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        ":bit_manipulation",
        "@googletest//:gtest_main",
    ],
)