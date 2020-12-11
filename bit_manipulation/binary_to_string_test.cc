#include "binary_to_string.h"

#include <gtest/gtest.h>

#include <string>

TEST(binaryToString, example) {
  EXPECT_EQ(binaryToString(0.5), ".1");
  EXPECT_EQ(binaryToString(0.1875), ".0011");
  EXPECT_EQ(binaryToString(0.798), "ERROR");
}