// https://leetcode.com/problems/valid-parenthesis-string/description/

#include <gtest/gtest.h>

#include <string>
#include <unordered_map>

class Solution {
 public:
  bool checkValidString_jhonny(std::string s) {
    std::vector<std::vector<int>> memo(s.size(), std::vector<int>(s.size(), -1));
    return f(s, 0, 0, memo);
  }

  bool f(std::string& s, int position, int open, std::vector<std::vector<int>>& memo) {
    if (position >= s.size()) {
      return open == 0;
    }

    if (memo[position][open] != -1) return memo[position][open];

    bool isValid = false;
    switch (s[position]) {
      case '(':
        isValid |= f(s, position + 1, open + 1, memo);
        break;
      case ')':
        if (open > 0) {
          isValid |= f(s, position + 1, open - 1, memo);
        }
        break;
      default:
        isValid |= f(s, position + 1, open, memo) || f(s, position + 1, open + 1, memo) ||
                   f(s, position + 1, open - 1, memo);
        break;
    }

    memo[position][open] = isValid;
    return isValid;
  }

 public:
  bool checkValidString(std::string s) {
    std::vector<std::vector<int>> memo(s.size(), std::vector<int>(s.size(), -1));
    return isValidString(0, 0, s, memo);
  }

 private:
  bool isValidString(int index, int openCount, const std::string& str,
                     std::vector<std::vector<int>>& memo) {
    // If reached end of the string, check if all brackets are balanced
    if (index == str.size()) {
      return (openCount == 0);
    }

    // If already computed, return memoized result
    if (memo[index][openCount] != -1) {
      return memo[index][openCount];
    }

    bool isValid = false;
    // If encountering '*', try all possibilities
    if (str[index] == '*') {
      isValid |= isValidString(index + 1, openCount + 1, str, memo);  // Treat '*' as '('
      if (openCount) {
        isValid |= isValidString(index + 1, openCount - 1, str, memo);  // Treat '*' as ')'
      }
      isValid |= isValidString(index + 1, openCount, str, memo);  // Treat '*' as empty
    } else {
      // Handle '(' and ')'
      if (str[index] == '(') {
        isValid = isValidString(index + 1, openCount + 1, str, memo);  // Increment count for '('
      } else if (openCount) {
        isValid = isValidString(index + 1, openCount - 1, str, memo);  // Decrement count for ')'
      }
    }

    // Memoize and return the result
    return memo[index][openCount] = isValid;
  }
};

TEST(valid_parenthesis_string, test_one) {
  auto solution = Solution{};
  ASSERT_TRUE(solution.checkValidString("()"));
}

TEST(valid_parenthesis_string, test_two) {
  auto solution = Solution{};
  ASSERT_TRUE(solution.checkValidString("(*)"));
}

TEST(valid_parenthesis_string, test_three) {
  auto solution = Solution{};
  ASSERT_TRUE(solution.checkValidString("(*))"));
}

TEST(valid_parenthesis_string, test_four) {
  auto solution = Solution{};
  ASSERT_FALSE(solution.checkValidString(")*)"));
}

TEST(valid_parenthesis_string, test_six) {
  auto solution = Solution{};
  ASSERT_FALSE(
      solution.checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())"
                                "((*()()(((()((()*(())*(()**)()(())"));
}

TEST(valid_parenthesis_string, test_five) {
  auto solution = Solution{};
  ASSERT_TRUE(
      solution.checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(("
                                "(((())*)))()))(()((*()*(*)))(*)()"));
}

TEST(valid_parenthesis_string, test_seven) {
  auto solution = Solution{};
  ASSERT_TRUE(
      solution.checkValidString("**************************************************))))))))))))))))"
                                "))))))))))))))))))))))))))))))))))"));
}

TEST(valid_parenthesis_string, test_eight) {
  auto solution = Solution{};
  ASSERT_FALSE(solution.checkValidString(")"));
}

TEST(valid_parenthesis_string, test_nine) {
  auto solution = Solution{};
  ASSERT_TRUE(
      solution.checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(("
                                "(((())*)))()))(()((*()*(*)))(*)()"));
}