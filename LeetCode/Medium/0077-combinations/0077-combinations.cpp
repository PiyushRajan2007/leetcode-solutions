class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(int start, int n, int k) {
        // Base case
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // Generate combinations
        for (int i = start; i <= n; i++) {
            temp.push_back(i);

            backtrack(i + 1, n, k);

            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};