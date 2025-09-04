class Solution {
public:
    vector<int> fun(int node, int par, vector<vector<int>>& adj, unordered_map<int, char>& mp, vector<int>& v) {
        int n = adj.size();
        vector<int> ans(26);
        for(auto x : adj[node]) {
            if(x != par) {
                vector<int> a = fun(x, node, adj, mp, v);
                for(int i = 0; i < 26; i++) {
                    ans[i] += a[i];
                }
            }
        }
        ans[mp[node] - 97]++;
        v[node] = ans[mp[node] - 97];
        return ans;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, char> mp;
        for(int i = 0; i < n; i++) mp[i] = labels[i];
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> ans(n);
        fun(0, -1, adj, mp, ans);
        return ans;
    }
};