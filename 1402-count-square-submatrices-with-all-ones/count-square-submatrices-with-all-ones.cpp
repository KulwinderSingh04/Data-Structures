class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> grid(n, vector<int> (m, 0));
        int sum = 0;
        for(int i = 0; i < n; i++) {
            grid[i][0] = matrix[i][0];
            sum += grid[i][0];
        }
        for(int i = 1; i < m; i++) {
            grid[0][i] = matrix[0][i];
            sum += grid[0][i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) continue;
                int mn = min(grid[i][j - 1], min(grid[i - 1][j - 1], grid[i - 1][j]));
                grid[i][j] = 1 + mn;
                // cout << grid[i][j] << " ";
                sum += grid[i][j];
            }
            // cout << endl;
        }
        return sum;
    }
};