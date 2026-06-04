class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int num = num1; num <= num2; num++) {
            string s = to_string(num);
            int n = s.size();

            for (int i = 1; i < n - 1; i++) {
                if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                    (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};