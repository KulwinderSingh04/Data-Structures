class Solution {
public:
    int find(int x, vector<int>& par) {
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }
    void Union(int x, int y, vector<int>& par, vector<int>& rank) {
        x = find(x, par);
        y = find(y, par);
        if(rank[x] > rank[y]) {
            par[y] = x;
        } else if(rank[x] < rank[y]) {
            par[x] = y;
        } else {
            rank[x]++;
            par[y] = x;
        }
    }
    int notTakeKruskals(int n, int idx, vector<vector<int>>& edges) {
        int ans = 0;
        vector<int> par(n), rank(n);
        for(int i = 0; i < n; i++) par[i] = i;
        for(int i = 0; i < edges.size(); i++) {
            if(i == idx) continue;
            if(find(edges[i][0], par) != find(edges[i][1], par)) {
                Union(edges[i][0], edges[i][1], par, rank);
                ans += edges[i][2];
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++) if(par[i] == i) count++;
        if(count > 1) return -1;
        return ans;
    }
    int takeKruskals(int n, int idx, vector<vector<int>>& edges) {
        vector<int> par(n), rank(n);
        for(int i = 0; i < n; i++) par[i] = i;
        int ans = edges[idx][2];
        Union(edges[idx][0], edges[idx][1], par, rank);
        for(int i = 0; i < edges.size(); i++) {
            if(i == idx) continue;
            if(find(edges[i][0], par) != find(edges[i][1], par)) {
                Union(edges[i][0], edges[i][1], par, rank);
                ans += edges[i][2];
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++) if(par[i] == i) count++;
        if(count > 1) return -1;
        return ans;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        int mst = notTakeKruskals(n, -1, edges);
        vector<vector<int>> ans(2);
        for(int i = 0; i < edges.size(); i++) {
            int nt = notTakeKruskals(n, i, edges);
            int t = takeKruskals(n, i, edges);
            if(nt == -1 || nt > mst) {
                ans[0].push_back(edges[i][3]);
            } else if(t != -1 && t == mst) {
                ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};