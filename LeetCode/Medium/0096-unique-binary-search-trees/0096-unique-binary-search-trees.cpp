class Solution {
public:
    int numTrees(int n) {
        long long c = 1;
        // Using the relation: C_{i} = C_{i-1} * (4*i - 2) / (i + 1)
        for (int i = 1; i <= n; ++i) {
            c = c * (4 * i - 2) / (i + 1);
        }
        return c;
    }
};