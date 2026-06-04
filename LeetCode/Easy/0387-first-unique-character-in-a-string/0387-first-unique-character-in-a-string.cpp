class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        queue<pair<char, int>> q;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            q.push({s[i], i});

            while (!q.empty() && freq[q.front().first] > 1) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front().second;
    }
};