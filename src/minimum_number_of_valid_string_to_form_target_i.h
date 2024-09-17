//
// Created by jhonny on 9/16/24.
//

#ifndef CPPPLAYGROUND_MINIMUM_NUMBER_OF_VALID_STRING_TO_FORM_TARGET_I_H
#define CPPPLAYGROUND_MINIMUM_NUMBER_OF_VALID_STRING_TO_FORM_TARGET_I_H

#include <string>
#include <vector>

using std::string, std::vector;

class Node {
public:
    Node* lists[26];
    bool flag = false;

    Node();
};

class Trie {
public:
    Node* root;

    Trie();

    void insert(const string& word);

    int search(string &s,int i,int n,int dp[]);
};

class minimum_number_of_valid_string_to_form_target_i {
public:
    int minValidStrings(vector<string>& words, string target);
};

#endif //CPPPLAYGROUND_MINIMUM_NUMBER_OF_VALID_STRING_TO_FORM_TARGET_I_H
