class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int r = 0;
        int c = m - 1;
        int ans = 0;
        while(r < n && c >= 0) {
            if(grid[r][c] < 0) {
                ans += n - r;
                c--;
            }
            else r++;
        }
        return ans;
    }
};