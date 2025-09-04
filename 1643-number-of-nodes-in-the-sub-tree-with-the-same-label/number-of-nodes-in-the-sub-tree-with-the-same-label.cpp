class Solution {
public:
    void fun(int node, int par, vector<vector<int>>& adj, string& labels, vector<int>& v, vector<int>& ans) {
        int n = adj.size();
        int before = v[labels[node] - 97];
        for(auto x : adj[node]) {
            if(x != par) {
                fun(x, node, adj, labels, v, ans);
            }
        }
        v[labels[node] - 97]++;
        int after = v[labels[node] - 97];
        ans[node] = after - before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> ans(n), v(26);
        fun(0, -1, adj, labels, v, ans);
        return ans;
    }
};