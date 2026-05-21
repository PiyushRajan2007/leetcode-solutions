#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[10];
    TrieNode() {
        for (int i = 0; i < 10; i++) child[i] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;
        string s = to_string(num);

        for (char c : s) {
            int d = c - '0';
            if (!node->child[d]) {
                node->child[d] = new TrieNode();
            }
            node = node->child[d];
        }
    }

    int searchMaxPrefix(int num) {
        TrieNode* node = root;
        string s = to_string(num);
        int len = 0;

        for (char c : s) {
            int d = c - '0';
            if (!node->child[d]) break;
            node = node->child[d];
            len++;
        }

        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Build trie from arr1
        for (int x : arr1) insert(x);

        int ans = 0;

        // check arr2 against trie
        for (int y : arr2) {
            ans = max(ans, searchMaxPrefix(y));
        }

        return ans;
    }
};