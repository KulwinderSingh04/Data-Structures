class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<vector<int>>& v, int a) {
        vis[node] = 1;
        v[a].push_back(node);
        for(auto x : adj[node]) {
            if(vis[x] == 0) {
                dfs(x, adj, vis, v, !a);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> ans(n);
        vector<vector<int>> adj1(n), adj2(m);
        for(auto x : edges1) {
            int u = x[0];
            int v = x[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto x : edges2) {
            int u = x[0];
            int v = x[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<vector<int>> v1(2), v2(2);
        vector<int> vis1(n), vis2(m);
        dfs(0, adj1, vis1, v1, 0);
        dfs(0, adj2, vis2, v2, 0);
        for(auto x : v1) {
            for(auto y : x) {
                int a = v2[0].size();
                int b = v2[1].size();
                ans[y] = x.size() + max(a, b);
            }
        }
        return ans;
    }
};