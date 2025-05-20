class Solution {
public:
    int timer = 0;
    void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<int>& vis, vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto x : adj[node]) {
            if(x == par) continue;
            if(vis[x] == 0) {
                dfs(x, node, adj, tin, low, vis, bridges);
                low[node] = min(low[node], low[x]);
                if(tin[node] < low[x]) {
                    bridges.push_back({x, node});
                }
            } else {
                low[node] = min(low[node], low[x]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> tin(n), low(n);
        vector<int> vis(n);
        vector<vector<int>> bridges;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) dfs(i, -1, adj, tin, low, vis, bridges);
        }
        return bridges;
    }
};