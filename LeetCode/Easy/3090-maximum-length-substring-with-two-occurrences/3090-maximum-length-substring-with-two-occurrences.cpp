class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0;
        int mL = 0;
        int count[26] = {0}; 

        for (int r = 0; r < s.length(); ++r) {
            count[s[r] - 'a']++;
            while (count[s[r] - 'a'] > 2) {
                count[s[l] - 'a']--;
                l++;
            }

            
            mL = max(mL, r - l + 1);
        }

        return mL;
    }
};