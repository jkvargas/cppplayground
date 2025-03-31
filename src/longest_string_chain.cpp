// https://leetcode.com/problems/longest-string-chain/?envType=study-plan-v2&envId=dynamic-programming-grandmaster

#include <gtest/gtest.h>

#include <string>
#include <vector>

class Solution {
 public:
  int longestStrChain(std::vector<std::string> &words) {
    std::unordered_map<std::string, int> dp;

    // Sorting the list in terms of the word length.
    std::sort(words.begin(), words.end(), [](const std::string &word1, const std::string &word2) {
      return word1.size() < word2.size();
    });

    int longestWordSequenceLength = 1;

    for (const std::string &word : words) {
      int presentLength = 1;
      // Find all possible predecessors for the current word by removing one letter at a time.
      for (int i = 0; i < word.length(); i++) {
        std::string predecessor = word.substr(0, i) + word.substr(i + 1, word.length() + 1);
        if (dp.find(predecessor) != dp.end()) {
          int previousLength = dp[predecessor];
          presentLength = std::max(presentLength, previousLength + 1);
        }
      }
      dp[word] = presentLength;
      longestWordSequenceLength = std::max(longestWordSequenceLength, presentLength);
    }
    return longestWordSequenceLength;
  }
};

TEST(longest_string_chain, test_one) {
  std::vector<std::string> input = {"a", "b", "ba", "bca", "bda", "bdca"};
  Solution solution;
  ASSERT_EQ(4, solution.longestStrChain(input));
}