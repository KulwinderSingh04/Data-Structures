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
    bool equationsPossible(vector<string>& equations) {
        vector<int> par(26, 0);
        for(int i = 0; i < 26; i++) par[i] = i;
        int n = equations.size();
        vector<int> rank(26);
        for(int i = 0; i < n; i++) {
            if(equations[i][1] == '=') {
                Union(equations[i][0] - 97, equations[i][3] - 97, par, rank);
            }
        }
        for(int i = 0; i < n; i++) {
            if(equations[i][1] == '!') {
                int x = equations[i][0] - 97;
                int y = equations[i][3] - 97;
                if(find(x, par) == find(y, par)) return false;
            }
        }
        return true;
    }
};