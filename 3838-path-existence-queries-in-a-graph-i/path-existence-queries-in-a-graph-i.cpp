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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> par(n);
        for(int i = 0; i < n; i++) par[i] = i;
        vector<int> rank(n, 0);
        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i - 1] <= maxDiff) {
                Union(i, i - 1, par, rank);
            }
        }
        vector<bool> ans(queries.size(),false);
        for(int k = 0; k < queries.size(); k++) {
            int i = queries[k][0];
            int j = queries[k][1];
            if(find(i, par) == find(j, par)) ans[k] = true;
        }
        return ans;
    }
};