class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, unordered_set<int>> mp;

        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> s;

            for (int j = i; j < i + k; j++)
                s.insert(nums[j]);

            for (int x : s)
                mp[x].insert(i);
        }

        int ans = -1;

        for (auto &p : mp) {
            if (p.second.size() == 1)
                ans = max(ans, p.first);
        }

        return ans;
    }
};