class Solution {
public:
    int dfs1(int node, vector<vector<int>>& adj, vector<int>& good, vector<int>& vis, vector<int>& dp) {
        vis[node] = 1;
        int ans = good[node] == 1 ? 1 : -1;
        for(auto x : adj[node]) {
            if(vis[x] == 1) continue;
            int a = dfs1(x, adj, good, vis, dp);
            ans += a < 0 ? 0 : a;
        }
        return dp[node] = ans;
    }
    void dfs2(int node, vector<vector<int>>& adj, int val, vector<int>& good, vector<int>& vis, vector<int>& dp1, vector<int>& dp) {
        vis[node] = 1;
        dp[node] = dp1[node] + max(0, val);
        for(auto x : adj[node]) {
            if(vis[x] == 1) continue;
            dfs2(x, adj, dp[node] - max(0, dp1[x]), good, vis, dp1, dp);
        }
    }
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> dp1(n), dp2(n);
        vector<int> vis1(n), vis2(n);
        dfs1(0, adj, good, vis1, dp1);
        dfs2(0, adj, 0, good, vis2, dp1, dp2);
        return dp2;
    }
};