class Solution {
public:
    int minimumArea(int r1, int r2, int c1, int c2, vector<vector<int>>& grid) {
        int min_i = r2 + 1, min_j = c2 + 1, max_i = 0, max_j = 0;
        for(int i = r1; i < r2 + 1; i++) {
            for(int j = c1; j < c2 + 1; j++) {
                if(grid[i][j] == 1) {
                    min_i = min(min_i, i);
                    min_j = min(min_j, j);
                    max_i = max(max_i, i);
                    max_j = max(max_j, j);
                }
            }
        }
        if(min_i == r2 + 1) return 0;
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
    int utility(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 1e8;
        for(int row = 1; row < n; row++) {
            for(int col = 1; col < m; col++) {

                int topLeft = minimumArea(0, row - 1, 0, col - 1, grid);
                int topRight = minimumArea(0, row - 1, col, m - 1, grid);
                int bottom = minimumArea(row, n - 1, 0, m - 1, grid);

                res = min(res, topLeft + topRight + bottom);

                int top = minimumArea(0, row - 1, 0, m - 1, grid);
                int bottomLeft = minimumArea(row, n - 1, 0, col - 1, grid);
                int bottomRight = minimumArea(row, n - 1, col, m - 1, grid);

                res = min(res, top + bottomLeft + bottomRight);
            }
        }
        for(int row1 = 1; row1 < n - 1; row1++) {
            for(int row2 = row1 + 1; row2 < n; row2++) {

                int top = minimumArea(0, row1 - 1, 0, m - 1, grid);
                int mid = minimumArea(row1, row2 - 1, 0, m - 1, grid);
                int bottom = minimumArea(row2, n - 1, 0, m - 1, grid);

                res = min(res, top + mid + bottom);
            }
        }
        return res;
    }
    vector<vector<int>> rotate(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> grid2(m, vector<int> (n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid2[j][n - i - 1] = grid[i][j];
            }
        }
        return grid2;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int res = utility(grid);
        vector<vector<int>> grid2 = rotate(grid);
        res = min(res, utility(grid2));
        return res;
    }
};