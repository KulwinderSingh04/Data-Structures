class Solution {
public:
    typedef pair<int, int> pp;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        priority_queue<pair<int, pp>> pq;
        pq.push({0, {0, 0}});
        dis[0][0] = 0;
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int time = t.first;
            int r = t.second.first;
            int c = t.second.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(dis[nr][nc] > max(time, moveTime[nr][nc]) + 1) {
                    dis[nr][nc] = max(time, moveTime[nr][nc]) + 1;
                    pq.push({dis[nr][nc], {nr, nc}});
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};