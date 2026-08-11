class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0], i = 1;

        while (i < nums.size() && nums[i] == nums[i - 1] + 1)
            sum += nums[i++];

        unordered_map<int, bool> mp;

        for (int x : nums)
            mp[x] = true;

        while (mp[sum])
            sum++;

        return sum;
    }
};