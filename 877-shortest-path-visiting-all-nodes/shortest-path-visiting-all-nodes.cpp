class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        set<pair<int, int>> vis;
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; i++) {
            q.push({i, {1 << i, 0}});
            vis.insert({i, 1 << i});
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
                if(vis.find({x, p}) == vis.end()) {
                    q.push({x, {p, dis + 1}});
                    vis.insert({x, p});
                }
            }
        }
        return -1;
    }
};