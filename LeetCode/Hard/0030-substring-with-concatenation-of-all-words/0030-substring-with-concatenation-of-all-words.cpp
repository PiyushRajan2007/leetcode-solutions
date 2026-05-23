class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.size();

        int wordLen = words[0].size();
        int wordCount = words.size();

        int totalLen = wordLen * wordCount;

        unordered_map<string, int> mp;

        for (auto word : words) {
            mp[word]++;
        }

        // Try all possible offsets
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            // Move in chunks of wordLen
            for (int right = offset; right + wordLen <= n; right += wordLen) {

                string word = s.substr(right, wordLen);

                // Valid word
                if (mp.count(word)) {

                    window[word]++;
                    count++;

                    // Too many occurrences
                    while (window[word] > mp[word]) {

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Found valid concatenation
                    if (count == wordCount) {

                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }

                // Invalid word
                else {

                    window.clear();

                    count = 0;

                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};