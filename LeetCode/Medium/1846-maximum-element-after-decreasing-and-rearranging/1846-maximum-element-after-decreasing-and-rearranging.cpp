class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n + 1);

        for (int x : arr)
            cnt[min(x, n)]++;

        int ans = 0;

        for (int i = 1; i <= n; i++)
            ans = min(i, ans + cnt[i]);

        return ans;
    }
};