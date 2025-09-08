class Solution {
public:
    bool isSafe(string& a, string& b) {
        int count = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) count++;
        }
        return count <= 2;
    }
    int find(int x, vector<int>& par) {
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }
    void Union(int x, int y, vector<int>& par, vector<int>& rank) {
        x = find(x, par);
        y = find(y, par);
        if(x == y) return;
        if(rank[x] > rank[y]) {
            par[y] = x;
        } else if(rank[x] < rank[y]) {
            par[x] = y;
        } else {
            rank[x]++;
            par[y] = x;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> par(n), rank(n);
        for(int i = 0; i < n; i++) par[i] = i;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isSafe(strs[i], strs[j])) {
                    Union(i, j, par, rank);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) if(par[i] == i) ans++;
        return ans;
    }
};