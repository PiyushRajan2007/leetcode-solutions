class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int p : nums) {
            if (p == 2) {
                ans.push_back(-1);
                continue;
            }

            int k = 0;
            int temp = p;

            // count trailing 1s
            while (temp & 1) {
                k++;
                temp >>= 1;
            }

            ans.push_back(p - (1 << (k - 1)));
        }

        return ans;
    }
};