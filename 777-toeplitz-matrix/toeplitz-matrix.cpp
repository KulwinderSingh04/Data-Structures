class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j = 0; j < matrix[0].size(); j++) {
            int ele = matrix[0][j];
            for(int k1 = 0, k2 = j; k1 < n && k2 < m; k1++, k2++) {
                if(matrix[k1][k2] != ele) return false; 
            }
        }
        for(int i = 1; i < n; i++) {
            int ele = matrix[i][0];
            for(int k1 = i, k2 = 0; k1 < n && k2 < m; k1++, k2++) {
                if(matrix[k1][k2] != ele) return false; 
            }
        }
        return true;
    }
};