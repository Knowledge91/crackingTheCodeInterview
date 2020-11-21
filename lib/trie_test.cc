#include "trie.h"

#include <memory>

#include "gtest/gtest.h"

class TrieTest : public ::testing::Test {
 protected:
  void SetUp() override { trie0_ = std::make_unique<Trie>(); }

  std::unique_ptr<Trie> trie0_;
};

TEST_F(TrieTest, insertWord) {
  trie0_->insert("answer");
  EXPECT_FALSE(trie0_->search("b"));
  EXPECT_FALSE(trie0_->search("ans"));
  EXPECT_TRUE(trie0_->search("answer"));
};