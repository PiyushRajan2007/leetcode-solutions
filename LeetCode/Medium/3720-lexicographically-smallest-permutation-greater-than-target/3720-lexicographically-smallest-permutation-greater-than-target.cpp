class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        
        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string result = "";
        
        // DFS helper function
        function<bool(int, bool)> dfs = [&](int pos, bool is_greater) -> bool {
            // Base case: filled all positions
            if (pos == n) {
                return is_greater;
            }
            
            // Try each character from 'a' to 'z'
            for (char c = 'a'; c <= 'z'; c++) {
                if (freq[c - 'a'] == 0) continue;
                
                if (is_greater) {
                    // Already greater, use smallest available
                    result += c;
                    freq[c - 'a']--;
                    
                    if (dfs(pos + 1, true)) return true;
                    
                    freq[c - 'a']++;
                    result.pop_back();
                } else {
                    // Not yet greater, need to ensure result > target
                    if (c > target[pos]) {
                        // This makes us greater
                        result += c;
                        freq[c - 'a']--;
                        
                        if (dfs(pos + 1, true)) return true;
                        
                        freq[c - 'a']++;
                        result.pop_back();
                    } 
                    else if (c == target[pos]) {
                        // Match target[pos], keep trying
                        result += c;
                        freq[c - 'a']--;
                        
                        if (dfs(pos + 1, false)) return true;
                        
                        freq[c - 'a']++;
                        result.pop_back();
                    }
                    // Skip if c < target[pos]
                }
            }
            
            return false;
        };
        
        if (dfs(0, false)) return result;
        return "";
    }
};