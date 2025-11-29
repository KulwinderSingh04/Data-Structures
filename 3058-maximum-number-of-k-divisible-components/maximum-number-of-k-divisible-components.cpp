class Solution {
public:
    long long dfs(int node, vector<vector<int>>& adj, int& k, vector<int>& values, int& ans, vector<int>& vis) {
        vis[node] = 1;
        long long a = 0;
        for(auto x : adj[node]) {
            if(vis[x] == 0) a += dfs(x, adj, k, values, ans, vis);
        }
        a += values[node];
        if(a % k == 0) {
            ans++;
            return 0;
        }
        return a;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> v(n);
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans = 0;
        vector<int> vis(n);
        dfs(0, adj, k, values, ans, vis);
        return ans;
    }
};