class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        long long sum = accumulate(stones.begin(), stones.end(), 0LL);
        long long ans = sum;
        int i = stones.size() - 2;

        while (i >= 1) {
            sum -= stones[i + 1];
            ans = max(ans, sum - ans);
            i--;
        }

        return ans;
    }
};