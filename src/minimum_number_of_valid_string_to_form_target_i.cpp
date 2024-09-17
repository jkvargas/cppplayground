//
// Created by jhonny on 9/16/24.
//

#include "minimum_number_of_valid_string_to_form_target_i.h"
#include <limits>
#include <cstring>

const int INT_MAX = std::numeric_limits<int>::max();

int minimum_number_of_valid_string_to_form_target_i::minValidStrings(vector<string> &words, string target) {
    Trie trie;
    int dp[10001];
    for(const auto& i:words) {
        trie.insert(i);
    }
    int n = target.size();
    memset(dp,-1,sizeof(dp));
    int k = trie.search(target,0,n,dp);
    if(k>1e4)
        return -1;
    return k;
}

void Trie::insert(const string &word) {
    int n = word.size();
    Node *t=root;
    for(int i=0;i<n;i++) {
        int k = word[i]-'a';
        if(t->lists[k]==nullptr)
            t->lists[k]= new Node();
        t=t->lists[k];
    }
    t->flag=true;
}

int Trie::search(string &s,int i,int n,int dp[]) {
    if(i==n) {
        return 0;
    }
    if(dp[i]!=-1)
        return dp[i];
    int ans=1e6;
    Node *h =root;
    for(int j=i;j<n;j++) {
        int k = s[j]-'a';
        if(h->lists[k]!=NULL) {
            ans=std::min(ans,1+search(s,j+1,n,dp));
            h=h->lists[k];
        } else
            break;
    }
    return dp[i] = ans;
}

Trie::Trie() : root{new Node()} {
}

Node::Node() : flag{false} {
    for (auto n : lists) {
        n = nullptr;
    }
}
