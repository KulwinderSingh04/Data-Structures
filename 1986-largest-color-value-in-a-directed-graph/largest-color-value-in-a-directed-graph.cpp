class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int> q;
        int ans = 0, count = 0;
        vector<vector<int>> dp(n, vector<int> (26));
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) { 
                q.push(i);
                dp[i][colors[i] - 97] = 1;
                // ans = max(ans, dp[i][colors[i] - 97]);
            }
        }
        while(q.size()) {
            auto t = q.front();
            q.pop();
            count++;
            ans = max(ans, dp[t][colors[t] - 97]);
            for(auto x : adj[t]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    q.push(x);
                }
                int u = t;
                int v = x;
                for(int i = 0; i < 26; i++) {
                    if(colors[v] == i + 97) dp[v][i] = max(dp[v][i], 1 + dp[u][i]);
                    else dp[v][i] = max(dp[v][i], dp[u][i]);
                }
            }
        }
        return count == n ? ans : -1;
    }
};