class Solution {
public:
    void dfs(vector<vector<int>>& adj, int i, vector<int>& visited) {
        int n = adj.size();
        queue<int> q;
        q.push(i);
        // vector<int> visited(n);
        visited[i] = 1;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for(auto x : adj[t]) {
                if(visited[x] == 0) {
                    q.push(x);
                    visited[x] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    if(i == j) continue;
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(n);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                count++;
                dfs(adj, i, visited);
            }
        }
        return count;
    }
};