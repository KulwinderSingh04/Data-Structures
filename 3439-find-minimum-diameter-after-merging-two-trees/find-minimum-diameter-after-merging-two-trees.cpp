class Solution {
public:
    typedef pair<int, int> pp;
    pp bfs(int node, vector<vector<int>>& adj) {
        int n = adj.size();
        queue<pp> q;
        q.push({node, 0});
        vector<int> vis(n);
        vis[node] = 1;
        int a = 0;
        int dis = 0;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int vert = t.first;
            int dist = t.second;
            if(dist >= dis) {
                dis = dist;
                a = vert;
            }
            for(auto x : adj[vert]) {
                if(vis[x] == 0) {
                    q.push({x, dist + 1});
                    vis[x] = 1;
                }
            }
        }
        return {a, dis};
    }
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        auto [a, dis1] = bfs(0, adj);
        auto [b, dis] = bfs(a, adj);
        return dis;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int dis1 = treeDiameter(edges1);
        int dis2 = treeDiameter(edges2);
        return max({dis1, dis2, (dis1 + 1) / 2 + (dis2 + 1) / 2 + 1});
    }
};