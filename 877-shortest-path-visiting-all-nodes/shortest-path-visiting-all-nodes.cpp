class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> vis(n, vector<int> (1 << n));
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; i++) {
            q.push({i, {1 << i, 0}});
            vis[i][1 << i] = 1;
        }
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int node = t.first;
            int path = t.second.first;
            int dis = t.second.second;
            if(path == (1 << n) - 1) return dis;
            for(auto x : graph[node]) {
                int p = path | (1 << x);
                if(vis[x][p] == 0) {
                    q.push({x, {p, dis + 1}});
                    vis[x][p] = 1;
                }
            }
        }
        return -1;
    }
};