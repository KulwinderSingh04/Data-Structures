class Solution {
public:
    long long dfs(int i, int par, vector<vector<int>>& adj, vector<int>& cost, int& ans) {
        vector<long long> child;
        for(auto x : adj[i]) {
            if(x != par) {
                child.push_back(dfs(x, i, adj, cost, ans));
            }
        }
        long long mxScore = 0;
        if(child.size() > 0) {
            mxScore = *max_element(child.begin(), child.end());
            for(int j = 0; j < child.size(); j++) {
                if(child[j] != mxScore) {
                    ans++;
                }
            }
        }
        return mxScore + cost[i];

    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        dfs(0, -1, adj, cost, ans);
        return ans;

    }
};