class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        // Augment the string
        string t = "1" + s + "1";

        // Run Length Encoding
        vector<pair<char,int>> runs;
        int i = 0, n = t.size();

        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int ans = ones;

        // Look for 0 - 1 - 0 pattern
        for (int i = 1; i + 1 < (int)runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                ans = max(ans,
                          ones + runs[i - 1].second + runs[i + 1].second);
            }
        }

        return ans;
    }
};