class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(r == n - 1) return true;
        grid[r][c] = 1;
        for(int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 1) continue;
            bool a = dfs(nr, nc, grid);
            if(a) return a;
        }
        return false;
    }
    int fun(int mid, int n, int m, vector<vector<int>>& cells) {
        vector<vector<int>> grid(n, vector<int> (m));
        for(int i = 0; i <= mid; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 0) {
                bool a = dfs(0, j, grid);
                if(a) return a;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row;
        int m = col;
        int lo = 0;
        int hi = cells.size() - 1;
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(fun(mid, n, m, cells)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans + 1;
    }
};