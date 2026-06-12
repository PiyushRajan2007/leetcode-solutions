class Solution {
public:
    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 1;

        int n = s.size();

        for(int i = 0; i < n; i++) {

            // Odd length palindrome
            int left = i;
            int right = i;

            while(left >= 0 && right < n &&
                  s[left] == s[right]) {

                if(right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    start = left;
                }

                left--;
                right++;
            }

            // Even length palindrome
            left = i;
            right = i + 1;

            while(left >= 0 && right < n &&
                  s[left] == s[right]) {

                if(right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    start = left;
                }

                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};