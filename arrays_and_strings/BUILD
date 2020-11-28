load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "arrays_and_strings",
    srcs = glob(
        ["*.cc"],
        exclude = ["*_test.cc"],
    ),
    hdrs = glob(["*.h"]),
    visibility = ["//main:__pkg__"],
)
