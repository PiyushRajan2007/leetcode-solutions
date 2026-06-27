class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long,int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            if (freq[1] % 2)
                ans = max(ans, freq[1]);
            else
                ans = max(ans, freq[1] - 1);
        }

        for (auto &[start, cnt] : freq) {

            if (start == 1)
                continue;

            long long cur = start;
            int len = 0;

            while (true) {

                if (!freq.count(cur))
                    break;

                // Cannot continue upward
                if (freq[cur] < 2) {
                    len++;
                    break;
                }

                // Prevent overflow
                if (cur > 1000000000LL / cur) {
                    len++;
                    break;
                }

                long long nxt = cur * cur;

                // No next level -> current is center
                if (!freq.count(nxt)) {
                    len++;
                    break;
                }

                len += 2;
                cur = nxt;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};