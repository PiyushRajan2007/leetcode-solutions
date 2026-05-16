
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0];   // initialize with first element

        for (int i = 1; i < n; i++) {
            mn = std::min(mn, nums[i]);
        }

        return mn;
    }
};

