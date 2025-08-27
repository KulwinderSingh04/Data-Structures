class Solution {
public:
    vector<vector<int>> dir = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}}; 
    vector<int> clock = {2, 0, 3, 1};
    int fun(int r, int c, int di, int dj, int turn, int ele, int x, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(turn > 2) return 0;
        if(x != -1 && dp[r][c][turn][x] != -1) return dp[r][c][turn][x];
        int res = 0;
        for(int t = 0; t < 4; t++) {
            int nr = r + dir[t][0];
            int nc = c + dir[t][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] != ele) continue;
            if(x != -1 && t != clock[x] && (x != t)) continue;
            int a = grid[nr][nc];
            grid[nr][nc] = -1;
            if(di != dir[t][0] || dj != dir[t][1]) res = max(res, fun(nr, nc, dir[t][0], dir[t][1], turn + 1, ele == 2 ? 0 : 2, t, grid, dp));
            else res = max(res, fun(nr, nc, di, dj, turn, ele == 2 ? 0 : 2, x, grid, dp));
            grid[nr][nc] = a;
        }
        if(x == -1) return res + 1;
        return dp[r][c][turn][x] = res + 1;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>> (m, vector<vector<int>> (3, vector<int> (4, -1))));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) res = max(res, fun(i, j, 0, 0, 0, 2, -1, grid, dp));
            }
        }
        return res;
    }
};