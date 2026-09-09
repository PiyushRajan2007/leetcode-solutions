class Solution {
public:
    long long countCommas(long long n) {

        long long a = 1000, ans = 0;

        while (a <= n)
         {

            ans += n - a + 1;
            
            a *= 1000;
        }
        return ans;

    }
};