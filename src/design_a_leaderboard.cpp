// https://leetcode.com/problems/design-a-leaderboard/description/?envType=company&envId=bloomberg&favoriteSlug=bloomberg-thirty-days

#include <unordered_map>
#include <algorithm>
#include <vector>
#include <gtest/gtest.h>

class Player {
public:
    int score;
    int id;

    explicit Player(int id, int score) : score(score), id(id) {}
};

class Leaderboard {
  std::unordered_map<int, int> players;
 public:

  void addScore(int playerId, int score) {
      if (players.contains(playerId))
          players[playerId] += score;
      else
          players.emplace(playerId, score);
  }

  int top(int K) {
      std::vector<Player> item;
      for (const auto &v : players) {
          item.emplace_back(v.first, v.second);
      }

      std::make_heap(item.begin(), item.end(), [](const auto& a, const auto& b) { return a.score <= b.score; });

      auto result = 0;
      for ( int i = 0; i < K; i++) {
          result += item.front().score;
          item.pop_back();
      }

      return result;
  }

  void reset(int playerId) {
      players.erase(playerId);
  }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

TEST(design_a_leaderboard, test_one) {
    Leaderboard leaderboard{};
    leaderboard.addScore(1,82);   // leaderboard = [[1,73]];
    leaderboard.addScore(2,84);   // leaderboard = [[1,73],[2,56]];
    leaderboard.addScore(3,47);   // leaderboard = [[1,73],[2,56],[3,39]];
    leaderboard.addScore(4,86);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
    leaderboard.addScore(5,92);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
    leaderboard.addScore(6,74);
    leaderboard.addScore(7,34);
    leaderboard.addScore(8,67);
    leaderboard.addScore(9,76);
    leaderboard.addScore(10,73);
    ASSERT_EQ(344, leaderboard.top(4));
    ASSERT_EQ(344, leaderboard.top(4));
    ASSERT_EQ(634, leaderboard.top(8));
    leaderboard.reset(1);
    leaderboard.reset(2);     // returns 141 = 51 + 51 + 39;
}
