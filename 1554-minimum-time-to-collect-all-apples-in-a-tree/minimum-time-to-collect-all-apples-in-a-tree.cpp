class Solution {
public:
    int dfs(int node, int par, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int time = 0;
        for(auto x : adj[node]) {
            if(x != par) {
                int t = dfs(x, node, adj, hasApple);
                if(t || hasApple[x]) time += t + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0);
        int timer = 0;
        return dfs(0, -1, adj, hasApple);
    }
};