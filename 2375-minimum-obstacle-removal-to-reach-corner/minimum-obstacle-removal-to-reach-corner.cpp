class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = INT_MAX;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({grid[0][0], {0, 0}});
        grid[0][0] = -1;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int r = t.second.first;
            int c = t.second.second;
            // cout << r << " " << c << " " << t.second << endl;
            if(r == n - 1 && c == m - 1) ans = min(t.first, ans);
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == -1) continue;
                pq.push({t.first + grid[nr][nc], {nr, nc}});
                grid[nr][nc] = -1;
            }
        }
        return ans;
    }
};