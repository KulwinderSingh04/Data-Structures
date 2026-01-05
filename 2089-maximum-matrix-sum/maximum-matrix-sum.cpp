class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int n = matrix.size();
        int cnt = 0;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cnt += matrix[i][j] < 0;
                sum += abs(matrix[i][j]);
                mn = min(mn, abs(matrix[i][j]));
            }
        }
        return cnt % 2 ? sum - 2 * mn : sum;
    }
};