//
// Created by jhonny on 9/16/24.
//

#include <gtest/gtest.h>
#include "../src/minimum_number_of_valid_string_to_form_target_i.h"

TEST(minimum_number_of_valid_string_to_form_target_i, TestOne) {
    auto words = vector<string>{};
    words.emplace_back("abc");
    words.emplace_back("aaaaa");
    words.emplace_back("bcdef");

    auto solution = minimum_number_of_valid_string_to_form_target_i();
    EXPECT_EQ(3, solution.minValidStrings(words, "aabcdabc"));
}