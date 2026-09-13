class Solution {
public:
    int countCommon(vector<vector<int>>& A, vector<vector<int>>& B, int row, int col) {
        int n = A.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int ii = i + row;
                int jj = j + col;
                if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
                    if(A[i][j] == B[ii][jj] && A[i][j] == 1) cnt++;
                }
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int row_offset = 1 - n; row_offset <= n - 1; row_offset++) {
            for(int col_offset = 1 - n; col_offset <= n - 1; col_offset++) {
                ans = max(ans, countCommon(img1, img2, row_offset, col_offset));
            }
        }
        return ans;
    }
};