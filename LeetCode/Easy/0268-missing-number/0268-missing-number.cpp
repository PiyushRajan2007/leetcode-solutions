class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorR = 0;
        

        for (int i = 0; i <= n; i++) {
            xorR ^= i;
        }
        
     
        for (int m : nums) {
            xorR ^= m;
        }
        
        return xorR;
    }
};