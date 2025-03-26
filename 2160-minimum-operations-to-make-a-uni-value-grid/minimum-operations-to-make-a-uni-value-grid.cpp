class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        vector<int> v;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());
        int t = v.size();
        int avg = v[ t / 2];
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(abs(avg - grid[i][j]) % x == 0) {
                    ans += abs(avg - grid[i][j]) / x;
                }
                else return -1;
            }
        }
        return ans;
    }
};