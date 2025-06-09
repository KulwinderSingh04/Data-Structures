class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<int, int>>> v(n, vector<pair<int, int>> (m));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'X') v[i][j].first += 1;
                else if(grid[i][j] == 'Y') v[i][j].second += 1;

                if(i > 0) {
                    v[i][j].first += v[i - 1][j].first;
                    v[i][j].second += v[i - 1][j].second;
                }
                if(j > 0) {
                    v[i][j].first += v[i][j - 1].first;
                    v[i][j].second += v[i][j - 1].second;
                }
                if(i > 0 && j > 0) {
                    v[i][j].first -= v[i - 1][j - 1].first;
                    v[i][j].second -= v[i - 1][j - 1].second;
                }
                if(v[i][j].first != 0 && v[i][j].second == v[i][j].first) {
                    ans++;
                }
            }
        }
        return ans;
    }
};