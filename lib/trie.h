#include <array>
#include <iostream>
#include <memory>
#include <string>

const int kAlphabetSize = 26;

struct TrieNode {
  TrieNode() {
    for (int i = 0; i < kAlphabetSize; i++) {
      children[i] = nullptr;
    }
  }

  bool isEndOfWord = false;
  std::array<std::unique_ptr<TrieNode>, kAlphabetSize> children;
};

class Trie {
 public:
  Trie() : root_(std::make_unique<TrieNode>()) {}

  void insert(std::string string) {
    std::cout << "insert" << std::endl;
    TrieNode* node = root_.get();
    for (auto& character : string) {
      std::cout << character << std::endl;
      int index = character - 'a';
      std::cout << index << std::endl;
      if (node->children[index] == nullptr) {
        std::cout << "in here" << std::endl;
        node->children[index] = std::make_unique<TrieNode>();
      }
      std::cout << "still here" << std::endl;
      node = node->children[index].get();
    }
    node->isEndOfWord = true;
  }

  bool search(std::string string) {
    TrieNode* node = root_.get();
    for (auto& character : string) {
      int index = character - 'a';
      if (node->children[index] == nullptr) {
        return false;
      }
      node = node->children[index].get();
    }
    return node->isEndOfWord;
  }

 private:
  std::unique_ptr<TrieNode> root_;
};