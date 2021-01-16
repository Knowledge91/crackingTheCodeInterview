load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "lib",
    srcs = glob(
        ["*.cc"],
        exclude = ["*_test.cc"],
    ),
    hdrs = glob(["*.h"]),
    visibility = [
        "//linked_lists:__pkg__",
        "//main:__pkg__",
        "//stacks_and_queues:__pkg__",
        "//trees_and_graphs:__pkg__",
    ],
)

cc_test(
    name = "tests",
    srcs = glob(["*_test.cc"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        ":lib",
        "@googletest//:gtest_main",
    ],
)
