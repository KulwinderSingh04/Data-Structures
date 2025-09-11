class Solution {
public:
    int find(int x, vector<int>& par) {
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }
    void Union(int x, int y, vector<int>& par, vector<int>& rank) {
        x = find(x, par);
        y = find(y, par);
        if(rank[x] > rank[y]) {
            par[y] = x;
        } else if(rank[y] > rank[x]) {
            par[x] = y;
        } else {
            par[y] = x;
            rank[x]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        int n = vals.size();
        for(int i = 0; i < n; i++) mp[vals[i]].push_back(i);
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> par(n), rank(n);
        for(int i = 0; i < n; i++) par[i] = i;
        vector<bool> active(n, false);
        int res = n;
        for(auto x : mp) {
            for(auto y : mp[x.first]) {
                for(auto v : adj[y]) {
                    if(active[v] == true) {
                        if(find(y, par) != find(v, par)) {
                            Union(y, v, par, rank);
                        }
                    }
                }
                active[y] = true;
            }
            vector<int> node_par;
            for(auto y : x.second) {
                node_par.push_back(find(y, par));
            }
            sort(node_par.begin(), node_par.end());
            int count = 1;
            for(int i = 1; i < node_par.size(); i++) {
                if(node_par[i] == node_par[i - 1]) count++;
                else {
                    if(count > 1) res += count * (count - 1) / 2;
                    count = 1;
                }
            }
            if(count > 1) res += count * (count - 1) / 2;
        }
        return res;
    }
};