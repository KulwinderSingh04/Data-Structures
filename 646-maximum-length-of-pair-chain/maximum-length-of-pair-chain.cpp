class Solution {
public:
    int findLongestChain(vector<vector<int>>& A) {
        int ans = 0;
        int n = A.size();
        vector<int> dp(n, 1);
        sort(A.begin(), A.end());
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(A[j][1] < A[i][0]) {
                    if(dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};