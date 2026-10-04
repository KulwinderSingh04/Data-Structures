class Solution {
public:
    int MOD = 1e9 + 7;
    typedef vector<vector<long long>> Matrix;
    Matrix mul(Matrix& A, Matrix& B) {
        Matrix C(A.size(), vector<long long> (B[0].size()));
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B[0].size(); j++) {
                for(int k = 0; k < A[0].size(); k++) {
                    C[i][j] += A[i][k] * B[k][j] % MOD;
                }
            }
        }
        return C;
    }
    Matrix pow(Matrix T, long long n) {
        if(n == 0) return {{1, 0}, {0, 1}};
        Matrix half = pow(T, n / 2);
        Matrix res = mul(half, half);
        if(n % 2) return mul(T, res);
        return res;
    }
    int countGoodStrings(long long n) {
        Matrix mat(2, vector<long long> (2, 1));
        mat[1][1] = 0;
        mat = pow(mat, n - 1);
        return mat[0][0] % MOD * 2 % MOD;
    }
};