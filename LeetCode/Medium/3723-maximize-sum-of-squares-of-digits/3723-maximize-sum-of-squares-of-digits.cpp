class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        int rem = sum % 9;
        string ans(sum / 9, '9');
        if (rem > 0) {
            ans.push_back('0' + rem);
        }
        ans.append(num - ans.size(), '0');
        return ans;
    }
};