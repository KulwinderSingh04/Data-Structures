class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j = 0;
        vector<int> res;
        for(int t = 0; t < n + m; t++) {
            while(i >= 0 && j >= 0 && i < n && j < m) {
                res.push_back(mat[i][j]);
                i--;
                j++;
            }
            i++;
            if(j >= m) {
                j--;
                i++;
            }
            while(i >= 0 && j >= 0 && i < n && j < m) {
                res.push_back(mat[i][j]);
                i++;
                j--;
            }
            j++;
            if(i >= n) {
                i--;
                j++;
            }
        }
        return res;
    }
};