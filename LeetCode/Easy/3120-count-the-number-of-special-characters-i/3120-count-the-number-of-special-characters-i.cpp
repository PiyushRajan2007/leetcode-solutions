class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower[26] = {0};
        int upper[26] = {0};

        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                lower[ch - 'a'] = 1;
            } else {
                upper[ch - 'A'] = 1;
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) {
                count++;
            }
        }

        return count;
    }
};