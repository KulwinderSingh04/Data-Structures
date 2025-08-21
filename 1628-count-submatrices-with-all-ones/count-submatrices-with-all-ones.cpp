class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int c = 0;
            for(int j = m - 1; j >= 0; j--) {
                if(mat[i][j] == 1) c++;
                else c = 0;
                mat[i][j] = c;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) continue;
                int mn = 500;
                for(int k = i; k < n; k++) {
                    mn = min(mn, mat[k][j]);
                    ans += mn;
                }
            }
        }
        return ans;
    }
};