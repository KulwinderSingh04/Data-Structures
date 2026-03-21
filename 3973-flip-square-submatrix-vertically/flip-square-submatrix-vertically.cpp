class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int x1 = x;
        int y1 = y;
        int x2 = x + k - 1;
        int y2 = y + k - 1;
        for(int i = x1; i < x1 + k / 2; i++) {
            for(int j = y1; j < y1 + k; j++) {
                swap(grid[i][j], grid[x2][j]);
            }
            x2--;
        }
        return grid;
    }
};