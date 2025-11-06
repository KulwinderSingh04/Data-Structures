class Solution {
public:
    typedef pair<int, int> pp;
    int bfs(int node, vector<vector<int>>& adj) {
        queue<pp> q;
        int n = adj.size();
        q.push({node, 1});
        int ans = 1;
        vector<int> vis(n + 1);
        vis[node] = 1;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            ans = max(ans, t.second);
            for(auto x : adj[t.first]) {
                if(vis[x] == 0) {
                    q.push({x, t.second + 1});
                    vis[x] = 1;
                }
            }
        }
        return ans;
    }
    bool oddCycle(int node, int col, vector<vector<int>>& adj, vector<int>& color, vector<int>& v) {
        color[node] = col;
        v.push_back(node);
        for(auto x : adj[node]) {
            if(color[x] == col) {
                return false;
            }
            if(color[x] == -1) {
                bool a = oddCycle(x, !col, adj, color, v);
                if(!a) return a;
            }
        }
        return true;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> color(n + 1, -1);
        int ans = 0;
        for(int x = 1; x <= n; x++) {
            if(color[x] == -1) {
                vector<int> v;
                if(!oddCycle(x, 0, adj, color, v)) {
                    return -1;
                }
                int a = 0;
                for(auto l : v) a = max(a, bfs(l, adj));
                ans += a;
            }
        }
        return ans;
    }
};