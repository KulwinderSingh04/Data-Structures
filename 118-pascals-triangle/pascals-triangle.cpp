class Solution {
public:
    int MOD = 1e9 + 7;
    int com(int n, int r) {
        long long res = 1;
        for(int i = n; i > n - r; i--) {
            res *= i;
            if(n - i + 1 <= r) res /= n - i + 1;
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i = 0; i < numRows; i++) {
            vector<int> a(i + 1);
            v.push_back(a);
            for(int j = 0; j < i + 1; j++) {
                v[i][j] = com(i, j);
            }
        }
        return v;
    }
};