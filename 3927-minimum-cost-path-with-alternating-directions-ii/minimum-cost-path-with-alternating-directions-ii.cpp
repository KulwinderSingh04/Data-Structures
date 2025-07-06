class Solution {
public:
    typedef pair<long long, pair<int, int>> pp;

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({1, {0, 0}});
        vector<vector<int>> dir = {{0, 1}, {1, 0}};
        vector<vector<long long>> dist(m, vector<long long> (n, LLONG_MAX));
        dist[0][0] = 1;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int r = t.second.first;
            int c = t.second.second;
            long long dis = t.first;
            if(dis > dist[r][c]) continue;
            for(int i = 0; i < 2; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if(dist[nr][nc] > dis + 1LL * (nr + 1) * (nc + 1) + waitCost[nr][nc]) {
                    dist[nr][nc] = dis + 1LL * (nr + 1) * (nc + 1) + waitCost[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                } 
            }
        }
        return dist[m - 1][n - 1] - waitCost[m - 1][n - 1];
    }
};