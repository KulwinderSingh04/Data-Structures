class Solution {
public:
    int find(int i, vector<int>& par) {
        if(i == par[i]) return i;
        return par[i] = find(par[i], par);
    }

    void Union(int x, int y, vector<int>& par, vector<int>& size) {
        int x_par = find(x, par);
        int y_par = find(y, par);
        if(x_par == y_par) return;
        if(size[x_par] > size[y_par]) {
            par[y_par] = x_par;
            size[x_par] += size[y_par];
        }
        else {
            par[x_par] = y_par;
            size[y_par] += size[x_par];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> par(n * n);
        for(int i = 0; i < n * n; i++) par[i] = i;
        vector<int> size(n * n, 1);
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }
                int node1 = i * n + j;
                for(int k = 0; k < 4; k++) {
                    int nr = i + dir[k][0];
                    int nc = j + dir[k][1];
                    int node2 = nr * n + nc; 
                    if(nr < 0 || nr >= n || nc < 0 || nc >= n || grid[nr][nc] == 0) continue;
                    Union(node1, node2, par, size);
                }
            }
        }
        for(int i = 0; i < n * n; i++) if(par[i] == i) mx = max(mx, size[i]);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    continue;
                }
                int ans = 0;
                int node1 = i * n + j;
                unordered_set<int> s;
                for(int k = 0; k < 4; k++) {
                    int nr = i + dir[k][0];
                    int nc = j + dir[k][1];
                    int node2 = nr * n + nc; 
                    if(nr < 0 || nr >= n || nc < 0 || nc >= n || grid[nr][nc] == 0) continue;
                    int par_2 = find(node2, par);
                    if(s.find(par_2) == s.end()) {
                        ans += size[par_2];
                        s.insert(par_2);
                    } 
                }
                mx = max(mx, ans + 1);
            }
        }
        return mx;
    }
};