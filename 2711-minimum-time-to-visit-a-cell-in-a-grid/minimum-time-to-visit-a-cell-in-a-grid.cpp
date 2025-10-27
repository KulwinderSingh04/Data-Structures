class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int r = t.second.first;
            int c = t.second.second;
            int time = t.first;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(grid[nr][nc] <= time) {
                    if(dist[nr][nc] > time + 1) {
                        dist[nr][nc] = time + 1;
                        pq.push({time + 1, {nr, nc}});
                    }
                } else {
                    if(dist[nr][nc] > time + (grid[nr][nc] - time) / 2 * 2 + 1) {
                        dist[nr][nc] = time + (grid[nr][nc] - time) / 2 * 2 + 1;
                        
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};