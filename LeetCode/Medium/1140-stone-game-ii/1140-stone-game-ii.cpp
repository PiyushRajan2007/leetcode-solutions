class Solution {
public:
    int n;
    vector<int> suffix;
    int dp[101][101];

    int solve(int i, int M) {
        // No piles left
        if (i >= n)
            return 0;

        // Can take all remaining piles
        if (2 * M >= n - i)
            return suffix[i];

        // Already calculated
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Try taking X piles
        for (int X = 1; X <= 2 * M; X++) {

            // Total remaining - opponent's best
            int current = suffix[i] -
                          solve(i + X, max(M, X));

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // Suffix sum
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 1);
    }
};