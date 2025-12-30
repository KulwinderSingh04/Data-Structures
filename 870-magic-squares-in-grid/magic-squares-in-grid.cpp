class Solution {
public:
    int funRow(int r, int c, vector<vector<int>>& grid) {
        int sum = -1;
        for(int i = r; i < r + 3; i++) {
            int sumRow = 0;
            for(int j = c; j < c + 3; j++) {
                sumRow += grid[i][j];
            }
            if(sumRow == sum || sum == -1) sum = sumRow;
            else return -1;
        }
        return sum;
    }
    bool numCheck(int r, int c, vector<vector<int>>& grid) {
        set<int> st;
        for(int i = r; i < r + 3; i++) {
            for(int j = c; j < c + 3; j++) {
                st.insert(grid[i][j]);
            }
        }
        if(st.size() == 9 && *st.begin() == 1 && *prev(st.end()) == 9) return true;
        return false;
    }
    int funCol(int r, int c, vector<vector<int>>& grid) {
        int sum = -1;
        for(int j = c; j < c + 3; j++) {
            int sumCol = 0;
            for(int i = r; i < r + 3; i++) {
                sumCol += grid[i][j];
            }
            if(sumCol == sum || sum == -1) sum = sumCol;
            else return -1;
        }
        return sum;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < m - 2; j++) {
                if(!numCheck(i, j, grid)) continue;
                int rowSum = funRow(i, j, grid);
                int colSum = funCol(i, j, grid);
                int diag1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int diag2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
                // cout << rowSum << " " << colSum << " " << diag1 << " " << diag2 << endl;
                if(diag1 == diag2 && rowSum == diag1 && rowSum == colSum) count++;
            }
        }
        return count;
    }
};