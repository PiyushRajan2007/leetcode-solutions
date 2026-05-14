class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.back();  // maximum element should be n

        // Length of a good array must be n + 1
        if (nums.size() != n + 1) {
            return false;
        }

        // Check numbers 1 to n-1 appear exactly once
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }

        // Last two elements must both be n
        return nums[n - 1] == n && nums[n] == n;
    }
};