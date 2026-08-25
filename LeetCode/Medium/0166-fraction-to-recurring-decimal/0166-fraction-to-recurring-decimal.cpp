class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        long long n = abs((long long)numerator), d = abs((long long)denominator);
        res += to_string(n / d);
        long long rem = n % d;
        if (!rem) return res;
        res += ".";
        unordered_map<long long, int> seen;
        while (rem) {
            if (seen.count(rem)) {
                res.insert(seen[rem], "(");
                res += ")";
                break;
            }
            seen[rem] = res.length();
            rem *= 10;
            res += to_string(rem / d);
            rem %= d;
        }
        return res;
    }
};