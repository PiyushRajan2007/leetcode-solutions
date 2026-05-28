#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int bestIndex; // Stores the index of the best matching word passing through this node

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        bestIndex = -1;
    }
};

class Solution {
private:
    TrieNode* root;

    void insert(const string& word, int wordIdx, const vector<string>& wordsContainer) {
        TrieNode* curr = root;
        int len = word.length();
        
        // Traverse backwards to handle it as a suffix problem
        for (int i = len - 1; i >= 0; --i) {
            int charIdx = word[i] - 'a';
            if (!curr->children[charIdx]) {
                curr->children[charIdx] = new TrieNode();
            }
            curr = curr->children[charIdx];
            
            // If this node hasn't been visited, set the current word as the best
            if (curr->bestIndex == -1) {
                curr->bestIndex = wordIdx;
            } else {
                // Compare with the existing best word at this node
                int currBestIdx = curr->bestIndex;
                if (wordsContainer[wordIdx].length() < wordsContainer[currBestIdx].length()) {
                    curr->bestIndex = wordIdx;
                }
                // Tie-breaker: wordsContainer[wordIdx] occurred earlier, 
                // but since we iterate sequentially, wordIdx > currBestIdx is always true.
                // So we don't need to explicitly check for equal lengths.
            }
        }
    }

    int search(const string& query) {
        TrieNode* curr = root;
        int len = query.length();
        int lastValidBestIndex = root->bestIndex;

        // Traverse backwards matching the suffix
        for (int i = len - 1; i >= 0; --i) {
            int charIdx = query[i] - 'a';
            if (!curr->children[charIdx]) {
                break;
            }
            curr = curr->children[charIdx];
            lastValidBestIndex = curr->bestIndex;
        }
        return lastValidBestIndex;
    }

    // Optional but clean habit: Deep-clean allocated memory to avoid memory overhead
    void clearTrie(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                clearTrie(node->children[i]);
            }
        }
        delete node;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        root = new TrieNode();
        
        // Step 1: Find the global default best index (for empty suffix matches)
        int defaultBestIdx = 0;
        for (int i = 1; i < wordsContainer.size(); ++i) {
            if (wordsContainer[i].length() < wordsContainer[defaultBestIdx].length()) {
                defaultBestIdx = i;
            }
        }
        root->bestIndex = defaultBestIdx;

        // Step 2: Build the Trie
        for (int i = 0; i < wordsContainer.size(); ++i) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        // Step 3: Process the queries
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& q : wordsQuery) {
            ans.push_back(search(q));
        }

        // Clean up memory
        clearTrie(root);
        
        return ans;
    }
};