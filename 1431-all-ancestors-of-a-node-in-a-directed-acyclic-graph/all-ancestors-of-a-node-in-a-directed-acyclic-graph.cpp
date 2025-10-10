class Solution {
public:
    void dfs(int node, int par, vector<vector<int>>& adj, vector<vector<int>>& ans) {
        // if(node != par &&  (ans[node].size() == 0 || ans[node].back() != par)) ans[node].push_back(par);
        for(auto& x : adj[node]) {
            if(ans[x].size() == 0 || ans[x].back() != par) {
                ans[x].push_back(par);
                dfs(x, par, adj, ans);
            }
            
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // cout << edges.size();
        vector<vector<int>> adj(n);
        for(auto& x : edges) {
            adj[x[0]].push_back(x[1]);
        }
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) {
            dfs(i, i, adj, ans);
        }
        return ans;
    }
};