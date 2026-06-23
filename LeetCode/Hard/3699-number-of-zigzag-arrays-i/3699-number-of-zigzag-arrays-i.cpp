class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        vector<long long> up(m + 1);
        vector<long long> down(m + 1);

        vector<long long> newUp(m + 1);
        vector<long long> newDown(m + 1);

        vector<long long> prefUp(m + 1);
        vector<long long> prefDown(m + 1);

        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {

            prefUp[0] = prefDown[0] = 0;

            for (int i = 1; i <= m; i++) {
                prefUp[i] = (prefUp[i - 1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i - 1] + down[i]) % MOD;
            }

            for (int v = 1; v <= m; v++) {
                newUp[v] = prefDown[v - 1];
                newDown[v] = (prefUp[m] - prefUp[v] + MOD) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;

        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};