//
// Created by jhonny on 8/1/25.
//

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
    std::unordered_map<std::string, int> freq;

    for (const auto& word : words) {
      freq[word]++;
    }

    auto cmp = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
      if (a.second == b.second) return a.first < b.first;
      return a.second > b.second;
    };

    std::vector<std::pair<std::string, int>> v;

    for (const auto& pair : freq) {
      v.push_back(std::make_pair(pair.first, pair.second));
    }

    std::sort(v.begin(), v.end(), cmp);

    std::vector<std::string> result;
    int i = 0;
    for (auto pair : v) {
      if (i < k) {
        result.push_back(pair.first);
        i++;
      } else {
        break;
      }
    }

    return result;
  }
};
