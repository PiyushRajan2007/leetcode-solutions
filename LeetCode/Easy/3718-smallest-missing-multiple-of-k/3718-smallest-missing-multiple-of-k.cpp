class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_map<int,int>check;
        for(int num : nums){
            check[num]++;
        }
        int i = 1;
        while(1){
            int num = k*i;
            if(check[num] == 0)
             return num;
            i++;
        }
        return 0;
    }
};