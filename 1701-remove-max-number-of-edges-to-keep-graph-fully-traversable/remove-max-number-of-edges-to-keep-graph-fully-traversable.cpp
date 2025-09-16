class Solution {
public:
    int find(int x, vector<int>& par) {
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }
    void Union(int x, int y, vector<int>& par, vector<int>& rank) {
        x = find(x, par);
        y = find(y, par);
        if(rank[x] == rank[y]) {
            rank[x]++;
            par[y] = x;
        } else if(rank[x] > rank[y]) {
            par[y] = x;
        } else {
            par[x] = y;
        }
    }
    set<vector<int>> fun(int n, vector<vector<int>>& edges) {
        set<vector<int>> st;
        vector<int> par(n + 1), rank(n + 1);
        for(int i = 0; i <= n; i++) par[i] = i;
        for(auto x : edges) {
            if(find(x[1], par) != find(x[2], par)) {
                st.insert(x);
                Union(x[1], x[2], par, rank);
            }
        }
        int count = 0;
        for(int i = 1; i < n + 1; i++) if(par[i] == i) count++;
        if(count != 1) st.insert({-1, -1, -1});
        return st;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edge1, edge2;
        for(auto x : edges) {
            if(x[0] == 3) {
                edge1.push_back(x);
                edge2.push_back(x);
            } else if(x[0] == 1) {
                edge1.push_back(x);
            } else {
                edge2.push_back(x);
            }
        }
        sort(edge1.begin(), edge1.end(), greater<vector<int>> ());
        sort(edge2.begin(), edge2.end(), greater<vector<int>> ());
        set<vector<int>> s1 = fun(n, edge1);
        set<vector<int>> s2 = fun(n, edge2);
        if(s1.find({-1, -1, -1}) != s1.end() || s2.find({-1, -1, -1}) != s2.end()) return -1;
        for(auto x : s1) {
            s2.insert(x);
        }
        return edges.size() - s2.size();
    }
};