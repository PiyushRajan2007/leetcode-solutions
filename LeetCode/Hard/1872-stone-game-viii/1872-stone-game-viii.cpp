class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        long long sum = accumulate(stones.begin(), stones.end(), 0LL);
        long long ans = sum;

        for (int i = stones.size() - 2; i >= 1; i--) {
            sum -= stones[i + 1];
            ans = max(ans, sum - ans);
        }

        return ans;
    }
};