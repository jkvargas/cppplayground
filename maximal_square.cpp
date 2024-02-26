//
// Created by jhonny on 2/25/24.
//

#include "maximal_square.h"
#include <algorithm>

int maximal_square::maximalSquare(vector<vector<char>>& matrix) {
    auto max_square_length = 0;
    auto rows = matrix.size();
    auto cols = matrix[0].size();

    vector<vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));
    for ( int i = 0; i < matrix.size(); i++ ) {
        for ( int j = 0; j < matrix[0].size(); j++ ) {
            if ( matrix[i][j] == '1') {
                auto left = i > 0 ? dp[i - 1][j] : 0;
                auto top = j > 0 ? dp[i][j - 1] : 0;
                auto angle = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0;

                dp[i][j] = min(min(left, top), angle) + 1;
                max_square_length = std::max(max_square_length, dp[i][j]);
            }
        }
    }
    return max_square_length * max_square_length;
}
