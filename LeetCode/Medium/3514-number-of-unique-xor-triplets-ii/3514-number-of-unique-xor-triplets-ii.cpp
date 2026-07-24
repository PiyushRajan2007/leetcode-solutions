class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> dp1(MAXX, false);
        vector<bool> dp2(MAXX, false);
        vector<bool> dp3(MAXX, false);

        for (int x : nums)
            dp1[x] = true;

        for (int x : nums) {
            for (int v = 0; v < MAXX; v++) {
                if (dp1[v])
                    dp2[v ^ x] = true;
            }
        }

        for (int x : nums) {
            for (int v = 0; v < MAXX; v++) {
                if (dp2[v])
                    dp3[v ^ x] = true;
            }
        }

        int ans = 0;
        for (bool ok : dp3)
            if (ok) ans++;

        return ans;
    }
};