class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int k = 0; k < n - 1; k++) {
            for(int i = 0; i < n - 1; i++) {
                for(int j = 0; j < n - 1; j++) {
                    if(i >= j) {
                        if(grid[i + 1][j + 1] > grid[i][j]) swap(grid[i][j], grid[i + 1][j + 1]);
                    }
                    else if(grid[i + 1][j + 1] < grid[i][j]) swap(grid[i][j], grid[i + 1][j + 1]);
                }
            }
        }
        return grid;
    }
};