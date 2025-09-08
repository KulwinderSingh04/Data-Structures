class Solution {
public:
    typedef pair<int, int> pp;
    void dfs(int node, int par, vector<vector<pp>>& adj, int& ans) {
        for(auto x : adj[node]) {
            if(x.first != par) {
                if(x.second == 1) ans++;
                dfs(x.first, node, adj, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pp>> adj(n);
        for(auto x : connections) {
            adj[x[0]].push_back({x[1], 1});
            adj[x[1]].push_back({x[0], 0});
        }
        int ans = 0;
        dfs(0, -1, adj, ans);
        return ans;
    }
};