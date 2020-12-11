#include "flip_bit_to_win.h"

#include "gtest/gtest.h"

TEST(flipBitToWin, example) {
  EXPECT_EQ(flipBitToWin(0), 1);
  EXPECT_EQ(flipBitToWin(1), 2);
  EXPECT_EQ(flipBitToWin(1775), 8);
}