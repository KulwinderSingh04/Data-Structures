class Solution {
public:
    bool fun(int r, int c, int k, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(r + k > n || c + k > m) return false;
        // row check
        int rowSum = -1;
        for(int i = r; i < r + k; i++) {
            int sum = 0;
            for(int j = c; j < c + k; j++) {
                sum += grid[i][j];
            }
            if(rowSum != -1 && rowSum != sum) return false;
            rowSum = sum;
        }
        // col check
        for(int j = c; j < c + k; j++) {
            int sum = 0;
            for(int i = r; i < r + k; i++) {
                sum += grid[i][j];
            }
            if(rowSum != -1 && rowSum != sum) return false;
            rowSum = sum;
        }
        //diagonal check
        int sum = 0;
        for(int i = r, j = c; i < r + k && j < c + k; i++, j++) {
            sum += grid[i][j];
        }
        if(rowSum != sum) return false;
        sum = 0;
        for(int i = r, j = c + k - 1; i < r + k && j >= c; i++, j--) {
            sum += grid[i][j];
        }
        if(rowSum != sum) return false;
        return true;


    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 1; k <= min(n, m); k++) {
                    if(fun(i, j, k, grid)) {
                        ans = max(ans, k);
                    }
                }
            }
        }
        return ans;
    }
};