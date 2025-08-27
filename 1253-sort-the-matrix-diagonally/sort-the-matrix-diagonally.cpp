class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1; j++) {
                for(int k = 0; k < m - 1; k++) {
                    if(mat[j][k] > mat[j + 1][k + 1]) swap(mat[j][k], mat[j + 1][k + 1]);
                }
            }
        }
        return mat;
    }
};