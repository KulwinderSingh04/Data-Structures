class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rows(n), cols(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int i = 0;
        int j = n - 1;
        while(rows[i] == 0) i++;
        while(rows[j] == 0) j--;
        int height = j - i + 1;
        i = 0, j = m - 1;
        while(cols[i] == 0) i++;
        while(cols[j] == 0) j--;
        return height * (j - i + 1);
    }
};