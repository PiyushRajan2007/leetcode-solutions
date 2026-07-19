class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> vis(26, false);

        // Count frequency of each character
        for (char c : s)
            freq[c - 'a']++;

        string ans;

        for (char c : s) {
            freq[c - 'a']--;

            // Skip if already included
            if (vis[c - 'a'])
                continue;

            // Maintain lexicographically smallest order
            while (!ans.empty() &&
                   ans.back() > c &&
                   freq[ans.back() - 'a'] > 0) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            vis[c - 'a'] = true;
        }

        return ans;
    }
};