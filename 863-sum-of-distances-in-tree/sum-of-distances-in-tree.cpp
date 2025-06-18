class Solution {
public:
    int dfs(int i, vector<vector<int>>& adj, vector<int>& count, vector<int>& vis) {
        vis[i] = 1;
        int ans = 0;
        for(auto x : adj[i]) {
            if(vis[x] == 0) {
                ans +=  dfs(x, adj, count, vis);
                count[i] += count[x];
            }
        }
        count[i]++;
        return count[i] + ans;
    }
    void dfs2(int i, vector<vector<int>>& adj, vector<int>& count, vector<int>& vis, vector<int>& ans) {
        vis[i] = 1;
        for(auto x : adj[i]) {
            if(vis[x] == 0) {
                ans[x] = ans[i] - count[x] + adj.size() - count[x];
                dfs2(x, adj, count, vis, ans);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n);
        vector<int> vis(n);
        vector<int> count(n);
        ans[0] = dfs(0, adj, count, vis) - n;
        vector<int> vis2(n);
        dfs2(0, adj, count, vis2, ans);
        return ans;
    }
};