// https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/3025/

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Node {
 public:
  Node* left;
  Node* right;
  char value;
  explicit Node(char x) : value(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  std::string alienOrder(std::vector<std::string>& words) {
    std::vector<std::pair<char, char>> v;

    for (auto i = 0; i < words.size() - 1; ++i) {
      auto first = words[i];
      auto second = words[i + 1];

      for (int j = 0; j < std::min(first.size(), second.size()); j++) {
        if (first[j] != second[j]) {
          v.emplace_back(first[j], second[j]);
        }
      }
    }

    return "test";
  }
};
