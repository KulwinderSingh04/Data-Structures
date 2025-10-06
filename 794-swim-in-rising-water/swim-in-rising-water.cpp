class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        dist[0][0] = grid[0][0];
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int r = t.second.first;
            int c = t.second.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(dist[nr][nc] > max(t.first, grid[nr][nc])) {
                    dist[nr][nc] = max(t.first, grid[nr][nc]);
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};