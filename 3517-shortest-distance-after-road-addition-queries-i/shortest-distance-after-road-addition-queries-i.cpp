class Solution {
public:
    typedef pair<int, int> pp;
    int bfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n);
        queue<pp> q;
        vis[0] = 1;
        q.push({0, 0});
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int node = t.first;
            int step = t.second;
            if(node == n - 1) return step;
            for(auto x : adj[node]) {
                if(vis[x] != 1) {
                    vis[x] = 1;
                    q.push({x, step + 1});
                }
            }
        }
        return 0;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        vector<int> ans;
        for(auto x : queries) {
            adj[x[0]].push_back(x[1]);
            ans.push_back(bfs(adj));
        }
        return ans;
    }
};