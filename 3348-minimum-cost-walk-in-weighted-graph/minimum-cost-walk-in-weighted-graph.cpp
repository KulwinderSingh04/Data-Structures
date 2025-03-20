class Solution {
public:
    int find(vector<int>& par, int a) {
        if(par[a] == a) return a;
        return par[a] = find(par, par[a]);
    }
    void Union(vector<int>& par, int x, int y) {
        par[x] = y;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        vector<int> par(n);
        vector<int> cost(n, -1);
        for(int i = 0; i < n; i++) par[i] = i;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int par_u = find(par, u);
            int par_v = find(par, v);
            if(par_u != par_v) {
                Union(par, par_u, par_v);
                cost[par_v] &= cost[par_u];
            }
            cost[par_v] &= edge[2];
        }
        vector<int> ans;
        for(int i = 0; i < q.size(); i++) {
            int s = q[i][0];
            int d = q[i][1];
            if(s == d) ans.push_back(0);
            else if(find(par, s) == find(par, d)) ans.push_back(cost[find(par, s)]);
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};