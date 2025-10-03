class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<vector<int>> vis(n, vector<int> (m));
        for(int j = 0; j < m; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[n - 1][j], {n - 1, j}});
            vis[0][j] = 1;
            vis[n - 1][j] = 1;
        }
        for(int i = 1; i < n - 1; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m - 1], {i, m - 1}});
            vis[i][0] = 1;
            vis[i][m - 1] = 1;
        }
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int r = t.second.first;
            int c = t.second.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] == 1) continue;
                if(t.first - heightMap[nr][nc] > 0) {
                    ans += t.first - heightMap[nr][nc];
                    pq.push({t.first, {nr, nc}});
                } else pq.push({heightMap[nr][nc], {nr, nc}});
                vis[nr][nc] = 1;
            }
        }
        return ans;
    }
};