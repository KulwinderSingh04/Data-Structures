class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {0, 0}});
        dis[0][0] = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int dist = t.first;
            int r = t.second.first;
            int c = t.second.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(dis[nr][nc] > max(dist, abs(heights[r][c] - heights[nr][nc]))) {
                    dis[nr][nc] = max(dist, abs(heights[r][c] - heights[nr][nc]));
                    pq.push({dis[nr][nc],{nr, nc}});
                }
            }
        }

        return dis[n - 1][m - 1];
    }
};