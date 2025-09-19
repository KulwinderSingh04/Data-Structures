class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(roads.size() == 0) return 0;
        vector<vector<int>> adj(n, vector<int> (n));
        vector<int> degree(n);
        for(auto x : roads) {
            degree[x[0]]++;
            degree[x[1]]++;
            adj[x[0]][x[1]] = 1;
            adj[x[1]][x[0]] = 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int x = degree[i]+ degree[j];
                if(adj[i][j] == 1) x--; 
                if(x >= ans) ans = x;
            }
        }
        return ans;

    }
};