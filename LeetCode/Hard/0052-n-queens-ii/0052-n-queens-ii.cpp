class Solution {
public:
    int ans = 0;

    void solve(int row, int n,
               vector<int>& cols,
               vector<int>& diag1,
               vector<int>& diag2) {

        if (row == n) {
            ans++;
            return;
        }

        for (int col = 0; col < n; col++) {

            if (cols[col] ||
                diag1[row - col + n - 1] ||
                diag2[row + col])
                continue;

            cols[col] = 1;
            diag1[row - col + n - 1] = 1;
            diag2[row + col] = 1;

            solve(row + 1, n, cols, diag1, diag2);

            cols[col] = 0;
            diag1[row - col + n - 1] = 0;
            diag2[row + col] = 0;
        }
    }

    int totalNQueens(int n) {

        vector<int> cols(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);

        solve(0, n, cols, diag1, diag2);

        return ans;
    }
};