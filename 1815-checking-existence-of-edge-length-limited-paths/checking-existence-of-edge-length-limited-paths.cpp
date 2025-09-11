class Solution {
public:
    int find(int x, vector<int>& par) {
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }
    void Union(int x, int y, int wt, vector<int>& par) {
        x = find(x, par);
        y = find(y, par);
        if(x == y) return;
        par[x] = y;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        for(int i = 0; i < queries.size(); i++) queries[i].push_back(i);

        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        vector<bool> ans(queries.size(), false);
        int i = 0;
        vector<int> par(n), cost(n, -1);
        for(int i = 0; i < n; i++) par[i] = i;
        for(int j = 0; j < queries.size(); j++) {
            while(i < edgeList.size() && edgeList[i][2] < queries[j][2]) {
                if(find(edgeList[i][0], par) != find(edgeList[i][1], par)) {
                    Union(edgeList[i][0], edgeList[i][1], edgeList[i][2], par);
                }
                i++;
            }
            if(find(queries[j][0], par) == find(queries[j][1], par)) {
                ans[queries[j][3]] = true;
            }
        }
        return ans;
    }
};