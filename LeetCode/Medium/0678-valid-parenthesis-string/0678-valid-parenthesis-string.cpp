class Solution {
public: 
    bool checkValidString(string s) {
        int n = s.size();
        
        vector<vector<bool>> dp(n + 1, vector<bool> (n + 1, false));
        
        dp[n][0] = true;

        for (int index = n - 1; index >= 0; index--) {
            for (int openBracket = 0; openBracket <= n; openBracket++) {
                bool isValid = false;

                
                if (s[index] == '*') {
                    isValid |= dp[index + 1][openBracket + 1];

                    
                    if (openBracket > 0) {
                        isValid |= dp[index + 1][openBracket - 1]; 
                    }
                    isValid |= dp[index + 1][openBracket]; 
                } else {
                   
                    if (s[index] == '(') {
                        isValid |= dp[index + 1][openBracket + 1]; 
                    } else if (openBracket > 0) {
                        isValid |= dp[index + 1][openBracket - 1]; 
                    }
                }
                dp[index][openBracket] = isValid;
            }
        }

        return dp[0][0]; 
    }
};