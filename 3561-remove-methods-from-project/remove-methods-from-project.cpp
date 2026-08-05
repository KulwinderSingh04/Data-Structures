class Solution {
public:
    int find(int x, vector<int>& par) {
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }
    void Union(int x, int y, vector<int>& par, vector<int>& rank) {
        x = find(x, par);
        y = find(y, par);
        if(x == y) return;
        if(rank[x] == rank[y]) {
            rank[x]++;
            par[y] = x;
        } else if(rank[x] > rank[y]) par[x] = y;
        else par[y] = x;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& v) {
        vis[node] = 1;
        v.push_back(node);
        for(auto x : adj[node]) {
            if(vis[x] == 0) {
                dfs(x, adj, vis, v);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> par(n), rank(n);
        for(int i = 0; i < n; i++) par[i] = i;
        for(int i = 0; i < invocations.size(); i++) {
            Union(invocations[i][0], invocations[i][1], par, rank);
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int> v1;
        vector<int> vis(n);
        dfs(k, adj, vis, v1);
        int p = -1;
        vector<vector<int>> grp(n);
        for(int i = 0; i < n; i++) {
            int pp = find(i, par);
            grp[pp].push_back(i);
        }
        sort(v1.begin(), v1.end());
        // return v1;
        for(auto& x : grp) {
            sort(x.begin(), x.end());
            
            if(x == v1) {
                // for(auto y : x) cout << y <<" ";
                // cout << endl;
                int j = 0;
                vector<int> ans;
                for(int i = 0; i < n; i++) {
                    if(j < v1.size() && i == v1[j]) j++;
                    else ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> a;
        for(int i = 0; i < n; i++) {
            a.push_back(i);
        }
        return a;
        
    }
};