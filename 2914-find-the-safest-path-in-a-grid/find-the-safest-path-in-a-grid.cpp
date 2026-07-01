class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int fun(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int> (n, INT_MIN));
        priority_queue<pp> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int r = t.second.first;
            int c = t.second.second;
            int val = t.first;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(dist[nr][nc] < min(val, grid[nr][nc])) {
                    dist[nr][nc] = min(val, grid[nr][nc]);
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        return dist[n - 1][n - 1];
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return 0;
        vector<vector<int>> mat(n, vector<int> (n, INT_MAX));
        vector<vector<int>> vis = mat;
        queue<pp> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int r = t.second.first;
            int c = t.second.second;
            int dis = t.first;
            mat[r][c] = min(mat[r][c], dis);
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n || vis[nr][nc] == 1) continue;
                q.push({dis + 1, {nr, nc}});
                vis[nr][nc] = 1;
            }
        }
        return fun(mat);
    }
};