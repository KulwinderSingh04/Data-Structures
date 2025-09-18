class Solution {
public:
    double distCalc(int x1, int y1, int x2, int y2) {
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }
    int dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        int ans = 1;
        for(auto x : adj[node]) {
            if(vis[x] == 0) {
                ans += dfs(x, adj, vis);
            }
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                double dis = distCalc(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]);
                if(dis <= bombs[i][2]) {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<int> vis(n);
            ans = max(ans, dfs(i, adj, vis));
        }
        return ans;
    }
};