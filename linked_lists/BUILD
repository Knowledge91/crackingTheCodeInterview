load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "linked_lists",
    srcs = glob(
        ["*.cc"],
        exclude = ["*_test.cc"],
    ),
    hdrs = glob(["*.h"]),
    visibility = ["//main:__pkg__"],
)
