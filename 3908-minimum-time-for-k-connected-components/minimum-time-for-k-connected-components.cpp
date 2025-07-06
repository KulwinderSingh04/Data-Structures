bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] > b[2];
}
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
    int fun(int n, vector<vector<int>>& edges) {
        vector<int> par(n), rank(n);
        for(int i = 0; i < n; i++) par[i] = i;

        for(auto edge : edges) {
            if(find(edge[0], par) != find(edge[1], par)) {
                Union(edge[0], edge[1], par, rank);
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++) if(par[i] == i) count++;
        // cout << count << " ";
        return count ;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), cmp);
        vector<int> par(n), rank(n);
        int ans = n;
        if(fun(n, edges) == k) return 0;
        for(int i = 0; i < n; i++) par[i] = i;
        for(int i = 0; i < edges.size(); i++) {
            if(find(edges[i][0], par) != find(edges[i][1], par)) {
                if(ans == k) return edges[i][2];
                ans--;
                Union(edges[i][0], edges[i][1], par, rank);
            }
        }
        return 0;
    }
};