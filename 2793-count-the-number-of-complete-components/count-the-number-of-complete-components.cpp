class Solution {
public:
    void dfs(vector<vector<int>>& adj, int i, vector<int>& vis, int& count, int& sz) {
        vis[i] = 1;
        sz++;
        count += adj[i].size();
        // cout << count << " ";
        for(auto x : adj[i]) {
            if(vis[x] == 0) {
                dfs(adj, x, vis, count, sz);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                int count = 0, sz = 0;
                dfs(adj, i, vis, count, sz);
                if(count / 2 == (sz * (sz - 1) / 2)) ans++;
            }
        }
        return ans;
    }
};