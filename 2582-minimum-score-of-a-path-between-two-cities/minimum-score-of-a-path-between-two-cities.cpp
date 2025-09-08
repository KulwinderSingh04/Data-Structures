class Solution {
public:
    int find(int x, vector<int>& par) {
        if(par[x] == x) return x;
        return par[x] = find(par[x], par);
    }
    void Union(int x, int y, int dist, vector<int>& par, vector<int>& dis) {
        x = find(x, par);
        y = find(y, par);
        par[x] = y;
        dis[y] = min({dis[x], dis[y], dist});
    }
    typedef pair<int, int> pp;
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> par(n + 1), dis(n + 1, INT_MAX);
        for(int i = 0; i < n + 1; i++) par[i] = i;
        for(auto x : roads) {
            Union(x[0], x[1], x[2], par, dis);
        }
        int p = find(1, par);
        // cout << p << " " << find(n, par);
        return dis[p];
    }
};