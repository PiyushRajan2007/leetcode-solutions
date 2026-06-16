class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int w = n-1 ;
        int x = n-2 ;
        int y = 0 ;
        int z = 1;
        return (nums[w] * nums[x])  -  (nums[y] * nums[z]);
    }
};