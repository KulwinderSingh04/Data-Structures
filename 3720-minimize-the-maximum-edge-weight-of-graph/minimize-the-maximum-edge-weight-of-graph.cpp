class Solution {
public:
    typedef pair<int, int> pp;
    void dfs(int node, vector<vector<pp>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for(auto x : adj[node]) {
            if(vis[x.first] == 1) continue;
            dfs(x.first, adj, vis);
        }
    }
    bool fun(int mid, int n, vector<vector<int>>& edges) {
        vector<vector<pp>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            if(i > mid) break;
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> vis(n);
        dfs(0, adj, vis);
        for(int i = 0; i < n; i++) if(vis[i] == 0) return false;
        return true;
        
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        int lo = 0;
        int hi = edges.size() - 1;
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(fun(mid, n, edges)) {
                ans = edges[mid][2];
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
};