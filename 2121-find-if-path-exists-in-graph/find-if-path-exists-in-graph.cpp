class Solution {
public:
    bool dfs(int src, int dest, vector<vector<int>>& adj, vector<int>& vis) {
        if(src == dest) return true;
        vis[src] = 1;
        for(auto x : adj[src]) {
            if(vis[x] == 0) {
                bool a = dfs(x, dest, adj, vis);
                if(a) return a;
            } 
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n);
        return dfs(src, dest, adj, vis);
    }
};