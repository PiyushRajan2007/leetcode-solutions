class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long a = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + a * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<long long> multiplyMatVec(
        const Matrix& A,
        const vector<long long>& v
    ) {
        int n = A.size();

        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;

            for (int j = 0; j < n; j++) {
                cur = (cur + A[i][j] * v[j]) % MOD;
            }

            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int sz = 2 * m;

        Matrix T(sz, vector<long long>(sz, 0));

        // U_new(v) = sum_{x<v} D(x)
        for (int v = 1; v <= m; v++) {
            for (int x = 1; x < v; x++) {
                T[v - 1][m + (x - 1)] = 1;
            }
        }

        // D_new(v) = sum_{x>v} U(x)
        for (int v = 1; v <= m; v++) {
            for (int x = v + 1; x <= m; x++) {
                T[m + (v - 1)][x - 1] = 1;
            }
        }

        vector<long long> S2(sz, 0);

        // U2(v) = v - 1
        for (int v = 1; v <= m; v++) {
            S2[v - 1] = v - 1;
        }

        // D2(v) = m - v
        for (int v = 1; v <= m; v++) {
            S2[m + (v - 1)] = m - v;
        }

        Matrix P = power(T, n - 2);

        vector<long long> Sn = multiplyMatVec(P, S2);

        long long ans = 0;

        for (long long x : Sn)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};