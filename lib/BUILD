load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "hashtable",
    srcs = ["hashtable.cc"],
    visibility = ["//main:__pkg__"],
)

cc_test(
    name = "tests",
    srcs = glob(["*_test.cc"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@googletest//:gtest_main",
    ],
)
