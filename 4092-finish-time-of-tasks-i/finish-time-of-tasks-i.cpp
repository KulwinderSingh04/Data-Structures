class Solution {
public:
    typedef pair<long long, long long> pp;
    long long fun(int node, vector<vector<int>>& adj, vector<int>& base, vector<int>& vis) {
        vis[node] = 1;
        // if(adj[node].size() == 0) return {base[node], base[node]};
        long long mn = LLONG_MAX, mx = LLONG_MIN;
        for(auto x : adj[node]) {
            if(vis[x] == 0) {
                auto p = fun(x, adj, base, vis);
                mn = min(mn, p);
                mx = max(mx, p);
            }
        }
        if(mx == LLONG_MIN) {
            // cost[node] = base[node];
            return base[node];
        }
        return 2 * mx - mn + base[node];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n);
        return fun(0, adj, baseTime, vis);
    }
};