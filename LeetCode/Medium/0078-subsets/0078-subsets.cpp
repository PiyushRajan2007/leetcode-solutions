#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Add current subset
        result.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);          // include
            backtrack(i + 1, nums, current, result);
            current.pop_back();                  // exclude (backtrack)
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};
