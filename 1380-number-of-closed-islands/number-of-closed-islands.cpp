class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int fun(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1;
        if(r == 0 || r == n - 1 || c == 0 || c == m - 1) ans = 0;
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] || grid[nr][nc] == 1) continue;
            int x = fun(nr, nc, grid, vis);
            if(x == 0) ans = 0;
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) continue;
                if(vis[i][j] == 0) {
                    ans += fun(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};