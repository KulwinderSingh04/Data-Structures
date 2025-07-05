class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for(auto x : adj[node]) {
            if(vis[x] == 0) {
                dfs(x, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        vector<vector<int>> adj(n);
        for(auto edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                count++;
                dfs(i, adj, vis);
            }
        }
        return count - 1;
    }
};