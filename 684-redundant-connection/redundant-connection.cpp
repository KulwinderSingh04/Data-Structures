class Solution {
public:
    int fun(int node, int time, int par, vector<vector<int>>& adj, vector<int>& pathVis) {
        pathVis[node] = time;
        for(auto x : adj[node]) {
            if(x == par) continue;
            if(pathVis[x] != 0) {
                // cout << node << " " << x << " ";
                return pathVis[x];
            } else {
                int a = fun(x, time + 1, node, adj, pathVis);
                if(a) return a;
            }
        }
        pathVis[node] = 0;
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> ans, pathVis(n + 1);
        int t = fun(1, 1, -1, adj, pathVis);
        
        for(int i = n - 1; i >= 0; i--) {
            if(pathVis[edges[i][1]] >= t && pathVis[edges[i][0]] >= t) return {edges[i]};
        }
        return ans;
    }
};