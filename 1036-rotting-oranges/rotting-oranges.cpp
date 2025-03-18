class Solution {
public:
    typedef pair<pair<int, int>, int> pp;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> visited(n, vector<int> (m, 0));
        queue<pp> q;
        int tc = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) tc++;
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    grid[i][j] = 2;
                }
            }
        }
        int ans = 0;
        int count = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(q.size()) {
            auto t = q.front();
            q.pop();
            ans = t.second;
            count++;
            int r = t.first.first;
            int c = t.first.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] != 1) continue;
                q.push({{nr, nc}, t.second + 1});
                grid[nr][nc] = 2;
            }
        }
        return count == tc ? ans : -1;
    }
};