class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}};
    bool fun(int r, int c, int cnt, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(r == n - 1 && c == m - 1) {
            // if(grid[r][c] == '(') cnt++;
            // else cnt--;
            return cnt == 0;
        }
        if(dp[r][c][cnt] != -1) return dp[r][c][cnt];
        for(int i = 0; i < 2; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(grid[nr][nc] == '(') {
                bool a = fun(nr, nc, cnt + 1, grid, dp);
                if(a) return dp[r][c][cnt] = a;
            } else {
                if(cnt == 0) continue;
                bool a = fun(nr, nc, cnt - 1, grid, dp);
                if(a) return dp[r][c][cnt] = a;
            }
        }
        return dp[r][c][cnt] = false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m + n, -1)));
        if(grid[0][0] == ')') return false;
        return fun(0, 0, 1, grid, dp);
    }
};