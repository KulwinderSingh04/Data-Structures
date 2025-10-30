class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[0][0] = 0;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int cost = t.first;
            int r = t.second.first;
            int c = t.second.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n | nc < 0 || nc >= m) continue;
                if(grid[r][c] - 1 == i) {
                    if(dist[nr][nc] > cost) {
                        dist[nr][nc] = cost;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                } else {
                    if(dist[nr][nc] > cost + 1) {
                        dist[nr][nc] = cost + 1;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};