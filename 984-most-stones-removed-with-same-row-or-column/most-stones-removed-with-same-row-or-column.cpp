class Solution {
public:
    int find(int i, vector<int>& par) {
        if(i == par[i]) return i;
        return par[i] = find(par[i], par);
    }
    void Union(int x, int y, vector<int>& par, vector<int>& rank) {
        int x_par = find(x, par);
        int y_par = find(y, par);
        
        if(x_par == y_par) return;
        if(rank[x_par] == rank[y_par]) {
            par[x_par] = y_par;
            rank[y_par]++;
        }
        else if(rank[x_par] > rank[y_par]) {
            par[y_par] = x_par;
        }
        else {
            par[x_par] = y_par;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> edges;
        vector<int> par(n);
        for(int i = 0; i < n; i++) par[i] = i;
        vector<int> rank(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    Union(i, j, par, rank);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(par[i] == i) ans++;
        }
        return n - ans;
    }
};