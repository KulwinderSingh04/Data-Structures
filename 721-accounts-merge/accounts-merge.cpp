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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> m;
        vector<int> par(n);
        for(int i = 0; i < n; i++) par[i] = i;
        vector<int> rank(n);
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(m.find(accounts[i][j]) != m.end()) {
                    Union(m[accounts[i][j]], i, par, rank);
                }
                else m[accounts[i][j]] = i;
            }
        }
        vector<vector<string>> ans(n), res;
        for(int i = 0; i < n; i++) ans[i].push_back(accounts[i][0]);
        for(auto x : m) {
            int x_par = find(x.second, par);
            ans[x_par].push_back(x.first);
        }
        for(int i = 0; i < n; i++) {
            if(ans[i].size() > 1) {
                sort(ans[i].begin() + 1, ans[i].end());
                res.push_back(ans[i]);
            }
        }
        return res;
    }
};