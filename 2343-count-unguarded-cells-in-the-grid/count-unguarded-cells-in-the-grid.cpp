class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n));
        for(auto x : walls) {
            grid[x[0]][x[1]] = -1;
        }
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;
        for(auto x : guards) grid[x[0]][x[1]] = -1;
        for(auto x : guards) {
            grid[x[0]][x[1]] = -1;
            for(int i = 0; i < 4; i++) {
                int r = x[0] + dir[i][0];
                int c = x[1] + dir[i][1];
                while(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != -1) {
                    grid[r][c] = 10;
                    r = r + dir[i][0];
                    c = c + dir[i][1];
                }

            }
        }
        for(auto x : grid) {
            for(auto y : x) {
                if(y == 0) ans++;
            }
        }
        return ans;
    }
};