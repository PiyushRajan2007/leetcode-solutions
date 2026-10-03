class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> k;

       
        k.push(-1);

        int maxi = 0;

        for (int i = 0; i < s.size(); i++) {

    
            if (s[i] == '(') {
                k.push(i);
            }

            
            else {

           
                k.pop();

                
                if (k.empty()) {
                    k.push(i);
                }

                else {
                    maxi = max(maxi, i - k.top());
                }
            }
        }

        return maxi;
    }
};