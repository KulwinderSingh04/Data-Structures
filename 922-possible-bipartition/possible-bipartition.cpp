class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& adj, vector<int>& col) {
        col[node] = color;
        for(auto x : adj[node]) {
            if(col[x] == -1) {
                bool a = dfs(x, !color, adj, col);
                if(a == false) return a;
            } else if(col[x] == col[node]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for(auto x : dislikes) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> col(n + 1, -1);
        for(int i = 1; i <= n; i++) {
            if(col[i] == -1) {
                bool a = dfs(i, 0, adj, col);
                if(a == false) return false; 
            }
        }
        return true;
    }
};