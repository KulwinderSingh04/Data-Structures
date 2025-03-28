class Solution {
public:
    int find(int x, vector<int>& par) {
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }
    
    void Union(int x, int y, vector<int>& par, vector<int>& rank) {
        int x_par = find(x, par);
        int y_par = find(y, par);
        if(x_par == y_par) return;
        if(rank[x_par] == rank[y_par]) {
            par[x_par] = par[y_par];
            rank[y_par]++;
        }
        else if(rank[x_par] > rank[y_par]) {
            par[y_par] = par[x_par];
        }
        else {
            par[x_par] = par[y_par];
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        vector<int> rank(n);
        for(int i = 0; i < n; i++) par[i] = i;
        for(int i = 0; i < edges.size(); i++) {
            if(find(edges[i][0], par) != find(edges[i][1], par)) {
                Union(edges[i][0], edges[i][1], par, rank);
            }
        }
        unordered_map<int, int> m;
        long long res = 0;
        for(int i = 0; i < n; i++) {
            int p = find(i, par);
            m[p]++;
        }
        int rem = n;
        long long ans= 0;
        for(auto x : m) {
            ans += 1LL * x.second * (rem - x.second);
            // rem -= x.second;
        }
        return ans * 1LL / 2;
    }
};