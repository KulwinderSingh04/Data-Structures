class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long m = grid[0].size();
        vector<long long> rows(n), cols(m);
        long long rowSum = 0, colSum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rows[i] += grid[i][j];
                rowSum += grid[i][j];

                cols[j] += grid[i][j];
                colSum += grid[i][j];
            }
        }
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += rows[i];
            if(1LL * 2 * sum  == rowSum) return true;
        }
        sum = 0;
        for(int i = 0; i < m; i++) {
            sum += cols[i];
            if(2 * sum == colSum) return true;
        }
        return false;
    }
};