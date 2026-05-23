class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> k;

        // Base index
        k.push(-1);

        int maxi = 0;

        for (int i = 0; i < s.size(); i++) {

            // Opening bracket
            if (s[i] == '(') {
                k.push(i);
            }

            // Closing bracket
            else {

                // Remove matching opening bracket/index
                k.pop();

                // If stack becomes empty,
                // push current index as new base
                if (k.empty()) {
                    k.push(i);
                }

                // Valid substring found
                else {
                    maxi = max(maxi, i - k.top());
                }
            }
        }

        return maxi;
    }
};