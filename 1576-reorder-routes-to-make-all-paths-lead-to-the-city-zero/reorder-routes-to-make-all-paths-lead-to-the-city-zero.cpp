class Solution {
public:
    void dfs(int node, int par, vector<vector<int>>& adj, set<vector<int>>& st, int& ans) {
        for(auto x : adj[node]) {
            if(x != par) {
                if(st.find({node, x}) != st.end()) ans++;
                dfs(x, node, adj, st, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        set<vector<int>> st;
        vector<vector<int>> adj(n);
        for(auto x : connections) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            st.insert(x);
        }
        int ans = 0;
        dfs(0, -1, adj, st, ans);
        return ans;
    }
};