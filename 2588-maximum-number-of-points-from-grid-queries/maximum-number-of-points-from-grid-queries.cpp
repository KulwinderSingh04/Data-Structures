class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<pair<int, int>> sortedQ;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < queries.size(); i++) {
            sortedQ.push_back({queries[i], i});
        }
        sort(sortedQ.begin(),sortedQ.end());
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<int> res(k);
        int points = 0;
        grid[0][0] = -1;
        for(int i = 0; i < k; i++) {
            int val = sortedQ[i].first;
            int idx = sortedQ[i].second;
            while(pq.size() && pq.top().first < val) {
                auto t = pq.top();
                pq.pop();
                int r = t.second.first;
                int c = t.second.second;
                points++;
                for(int i = 0; i < 4; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == -1) continue;
                    pq.push({grid[nr][nc], {nr, nc}});
                    grid[nr][nc] = -1;
                }
            }
            res[idx] = points;
        }
        return res;
    }
};