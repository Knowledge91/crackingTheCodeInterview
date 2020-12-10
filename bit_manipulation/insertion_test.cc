#include "insertion.h"

#include <bitset>
#include <iostream>

#include "gtest/gtest.h"

TEST(insertionTest, insertion) { EXPECT_EQ(insertion(1024, 19, 2, 6), 1100); }