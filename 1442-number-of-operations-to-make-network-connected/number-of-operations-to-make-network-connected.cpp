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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        vector<int> par(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
        vector<int> rank(n);
        int cable = 0;
        for(int i = 0; i < connections.size(); i++) {
            if(find(connections[i][0], par) == find(connections[i][1], par)) cable++;
            else {
                Union(connections[i][0], connections[i][1], par, rank);
            }
        }
        int comp = 0;
        for(int i = 0; i < n; i++) if(par[i] == i) comp++;
        return cable >= comp - 1 ? comp - 1 : -1;
    }
};