class Solution {
public:
    typedef pair<int, int> pp;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        priority_queue<pair<pp, pp>, vector<pair<pp, pp>>, greater<pair<pp, pp>>> pq;
        pq.push({{0, 1}, {0, 0}});
        dis[0][0] = 0;
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int time = t.first.first;
            int sec = t.first.second;
            int r = t.second.first;
            int c = t.second.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                int newTime = max(time, moveTime[nr][nc]) + sec;
                if(dis[nr][nc] > newTime) {
                    dis[nr][nc] = newTime;
                    if(sec == 1) pq.push({{dis[nr][nc], 2}, {nr, nc}});
                    else pq.push({{dis[nr][nc], 1}, {nr, nc}});
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};