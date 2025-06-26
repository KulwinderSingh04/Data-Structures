class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (3)));

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) continue;
                int n1 = n;
                int m1 = m;
                for(int k1 = i; k1 < n1; k1++) {
                    for(int k2 = j; k2 < m1; k2++) {
                        if(mat[k1][k2] == 1) {
                            // cout << k1 << " " << k2 << endl;
                            ans++;
                        } else {
                            m1 = min(m1, k2);
                        }
                    }
                    if(mat[k1][j] == 0) n1 = min(n1, k1);
                }
            }
        }
        return ans;
    }
};