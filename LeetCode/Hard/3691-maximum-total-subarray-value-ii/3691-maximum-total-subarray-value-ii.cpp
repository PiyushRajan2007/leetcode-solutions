class Solution {
    using ll = long long;
public:
    long long maxTotalValue(vector<int>& a, int k) {
        int n = a.size(), LG = __lg(n) + 1;
        vector<int> lg(n + 1);
        for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;

        vector<vector<int>> mx(LG, vector<int>(n)),
                            mn(LG, vector<int>(n));

        for (int i = 0; i < n; i++)
            mx[0][i] = mn[0][i] = a[i];

        for (int j = 1; j < LG; j++)
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
                mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
            }

        auto val = [&](int l, int r) -> ll {
            int j = lg[r - l + 1];
            return (ll)max(mx[j][l], mx[j][r - (1 << j) + 1]) -
                   min(mn[j][l], mn[j][r - (1 << j) + 1]);
        };

        priority_queue<array<ll,3>> pq;
        for (int l = 0; l < n; l++)
            pq.push({val(l, n - 1), l, n - 1});

        ll ans = 0;
        while (k--) {
            auto [v, l, r] = pq.top();
            pq.pop();
            ans += v;
            if (r > l) pq.push({val(l, r - 1), l, r - 1});
        }
        return ans;
    }
};