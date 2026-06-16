class Solution {
public:
    string processStr(string s) {
        string p;
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                p.push_back(ch);
            } else if (ch == '*') {
                if (!p.empty())
                    p.pop_back();
            } else if (ch == '#') {
                p += p;
            } else if (ch == '%') {
                reverse(p.begin(), p.end());
            }
        }
        return p;
    }
};