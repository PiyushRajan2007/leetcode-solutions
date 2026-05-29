class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            int x = nums[i];

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            ans.push_back(sum);
        }

        int mini = ans[0];

        for (int i = 1; i < n; i++) {
            if (ans[i] < mini) {
                mini = ans[i];
            }
        }

        return mini;
    }
};