class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pp> pq;
        pq.push({health - grid[0][0], {0, 0}});
        vector<vector<int>> dist(n, vector<int> (m, INT_MIN));
        dist[0][0] = health - grid[0][0];
        vector<vector<int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int r = t.second.first;
            int c = t.second.second;
            int remHealth = t.first;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(dist[nr][nc] < remHealth - grid[nr][nc]) {
                    dist[nr][nc] = remHealth - grid[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        return dist[n - 1][m - 1] >= 1;
    }
};