class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, int k, int& ans, vector<int>& vis) {
        if(k < 0) return;
        vis[i] = 1;
        ans++;
        for(auto x : adj[i]) {
            if(vis[x] == 0 && k > 0) {
                dfs(x, adj, k - 1, ans, vis);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> ans(n);
        vector<vector<int>> adj1(n);
        for(auto edge : edges1) {
            int u = edge[0];
            int v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        vector<vector<int>> adj2(m);
        for(auto edge : edges2) {
            int u = edge[0];
            int v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        
        for(int i = 0; i < n; i++) {
            vector<int> vis(n);
            int a = 0;
            dfs(i, adj1, k, a, vis);
            ans[i] = a;
        }
        int mx = 0;
        for(int i = 0; i < m; i++) {
            vector<int> vis(m);
            int a = 0;
            dfs(i, adj2, k - 1, a, vis);
            mx = max(mx, a);
        }
        for(auto& x : ans) x += mx;
        return ans;
    }
};