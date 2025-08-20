class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int> (m, 0));
        int res = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(matrix[i][j] == 0) continue;
                int a = 0, b = 0, c = 0;
                if(i + 1 < n) a = ans[i + 1][j];
                if(j + 1 < m) b = ans[i][j + 1];
                if(i + 1 < n && j + 1 < m) c = ans[i + 1][j + 1];
                ans[i][j] = min({a, b , c}) + 1;
                res += ans[i][j];
            }
            cout << endl;
        }
        return res;
    }
};