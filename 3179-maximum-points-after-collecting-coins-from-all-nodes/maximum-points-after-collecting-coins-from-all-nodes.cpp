class Solution {
public:
    int fun(int node, int par, int factor, vector<vector<int>>& adj, vector<int>& coins, int k, vector<vector<int>>& dp) {
        if(factor > 14) return 0;
        if(dp[node][factor] != -1) return dp[node][factor];
        int res = 0;
        int a = coins[node] / (1 << factor) - k;
        int b = coins[node] / (1 << factor) / 2;
        for(auto x : adj[node]) {
            if(x != par) {
                a += fun(x, node, factor, adj, coins, k, dp);
                b += fun(x, node, factor + 1, adj, coins, k, dp);
            }
        }
        return dp[node][factor] = max(a, b);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<vector<int>> dp(n, vector<int> (15, -1));
        return fun(0, -1, 0, adj, coins, k, dp);
    }
};