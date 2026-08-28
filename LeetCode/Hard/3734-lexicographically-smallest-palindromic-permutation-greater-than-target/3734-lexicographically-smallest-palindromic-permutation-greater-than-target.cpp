class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size(), m = n / 2, mid = -1;
        vector<int> c(26);

        for (char x : s) c[x - 'a']++;

        for (int i = 0; i < 26; i++)
            if (c[i] & 1) {
                if (mid != -1) return "";
                mid = i;
            }

        vector<int> r(26);
        for (int i = 0; i < 26; i++) r[i] = c[i] / 2;

        string t = target.substr(0, m);

        vector<int> cnt = r;
        bool ok = true;

        for (char x : t)
            if (--cnt[x - 'a'] < 0) {
                ok = false;
                break;
            }

        auto build = [&](string h) {
            string ans = h;
            if (n & 1) ans += char('a' + mid);
            ans += string(h.rbegin(), h.rend());
            return ans;
        };

        if (ok) {
            string ans = build(t);
            if (ans > target) return ans;
        }
        for (int i = m - 1; i >= 0; i--) {
            cnt = r;

            for (int j = 0; j < i; j++)
                if (--cnt[t[j] - 'a'] < 0) {
                    cnt.clear();
                    break;
                }

            if (cnt.empty()) continue;

            for (int ch = t[i] - 'a' + 1; ch < 26; ch++) {
                if (!cnt[ch]) continue;

                string h = t.substr(0, i) + char('a' + ch);
                cnt[ch]--;

                for (int j = 0; j < 26; j++)
                    h += string(cnt[j], 'a' + j);

                return build(h);
            }
        }

        return "";
    }
};