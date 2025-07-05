class Solution {
public:
    int find(int x, vector<int>& par) {
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }
    void Union(int x, int y, vector<int>& par, vector<int>& rank) {
        int px = find(x, par);
        int py = find(y, par);
        if(rank[px] == rank[py]) {
            rank[px]++;
            par[py] = px;
        } else if(rank[px] > rank[py]) {
            par[py] = px;
        } else {
            par[px] = py;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        vector<int> par(n), rank(n);
        for(int i = 0; i < n; i++) par[i] = i;

        for(auto edge : connections) {
            if(find(edge[0], par) != find(edge[1], par)) {
                Union(edge[0], edge[1], par, rank);
            }
        }
        int count = -1;
        for(int i = 0; i < n; i++) if(par[i] == i) count++;
        return count;
    }
};