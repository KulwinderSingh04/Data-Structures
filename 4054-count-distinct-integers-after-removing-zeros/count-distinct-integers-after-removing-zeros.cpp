class Solution {
public:
    long long fun(int i, int tight, int cnt, string& str, vector<vector<vector<long long>>>& dp) {
        if(i == str.size()) return cnt != 0;
        if(dp[i][tight][cnt] != -1) return dp[i][tight][cnt];
        long long limit = (tight == 1 ? str[i] - '0' : 9);
        long long ans = 0;
        for(int j = 0; j <= limit; j++) {
            int newCnt = cnt || j;
            if(j == 0) {
                if(newCnt == 0) {
                    ans += fun(i + 1, (tight && (j == str[i] - '0')), newCnt, str, dp);
                }
            }
            else ans += fun(i + 1, (tight && (j == str[i] - '0')), newCnt, str, dp);
        }
        return dp[i][tight][cnt] = ans;
    }
    long long countDistinct(long long n) {
        string str = to_string(n);
        long long ans = 0;
        vector<vector<vector<long long>>> dp(17, vector<vector<long long>> (2, vector<long long> (2, -1)));
        return ans += fun(0, 1, 0, str, dp);
    }
};