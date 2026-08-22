class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int temp = n; 
        
        while (temp > 0) {
            int k = temp % 10;
            sum += k;
            prod *= k;
            temp /= 10;
        }
        
        return n % (sum + prod) == 0;
    }
};