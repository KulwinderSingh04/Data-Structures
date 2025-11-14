class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n, vector<int> (n));
        for(auto x : queries) {
            grid[x[0]][x[1]] += 1;
            if(x[3] + 1 < n) grid[x[0]][x[3] + 1] += -1;
            if(x[2] + 1 < n) grid[x[2] + 1][x[1]] += -1;
            if(x[3] + 1 < n && x[2] + 1 < n) grid[x[2] + 1][x[3] + 1] += 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                grid[i][j] += grid[i][j - 1];
            }
        }
        for(int j = 0; j < n; j++) {
            for(int i = 1; i < n; i++) {
                grid[i][j] += grid[i - 1][j];
            }
        }
        return grid;
    }
};