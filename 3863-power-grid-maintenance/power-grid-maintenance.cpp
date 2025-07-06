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
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> ans;
        
        vector<int> par(c + 1), rank(c + 1);
        for(int i = 1; i <= c; i++) par[i] = i;
        int n = connections.size();
        for(auto edge : connections) {
            if(find(edge[0], par) != find(edge[1], par)) {
                Union(edge[0], edge[1], par, rank);
            }
        }
        vector<set<int>> op(c + 1);
        unordered_set<int> nonOp;
        for(int i = 1; i < c + 1; i++)  {
            int pc = find(i, par);
            op[pc].insert(i);
        }
        for(int i = 0; i < q; i++) {
            if(queries[i][0] == 2) {
                int p = find(queries[i][1], par);
                op[p].erase(queries[i][1]);
                nonOp.insert(queries[i][1]);
            } else {
                if(nonOp.find(queries[i][1]) == nonOp.end()) ans.push_back(queries[i][1]);
                else {
                    int p = find(queries[i][1], par);
                    if(op[p].size()) ans.push_back(*(op[p].begin()));
                    else ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};