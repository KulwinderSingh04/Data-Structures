class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            degree[x[0]]++;
            degree[x[1]]++;
        }
        int tot = n;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) {
                q.push(i);
            }
        }
        while(tot > 2) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto t = q.front();
                q.pop();
                for(auto x : adj[t]) {
                    degree[x]--;
                    if(degree[x] == 1) q.push(x);
                }
            }
            tot -= sz;
        }
        if(q.size() == 1) return {q.front()};
        int a = q.front();
        q.pop();
        return {a, q.front()};
    }
};