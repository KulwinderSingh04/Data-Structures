class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = grid[r][c];
        grid[r][c] = 0;
        for(int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 0) continue;
            ans += dfs(nr, nc, grid);
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};