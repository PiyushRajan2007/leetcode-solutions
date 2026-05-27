class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lastLower[26];
        int firstUpper[26];

        // Initialize arrays
        for (int i = 0; i < 26; i++) {
            lastLower[i] = -1;
            firstUpper[i] = -1;
        }

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];

            // Lowercase letters: ASCII 'a' to 'z'
            if (ch >= 'a' && ch <= 'z') {
                lastLower[ch - 'a'] = i;
            }

            // Uppercase letters: ASCII 'A' to 'Z'
            else {
                if (firstUpper[ch - 'A'] == -1) {
                    firstUpper[ch - 'A'] = i;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {
                count++;
            }
        }

        return count;
    }
};