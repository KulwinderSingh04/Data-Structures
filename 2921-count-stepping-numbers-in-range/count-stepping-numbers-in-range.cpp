class Solution {
public:
    int MOD = 1e9 + 7;
    long long fun(int i, int tight, int flag, int prev, string& str, vector<vector<vector<vector<long long>>>>& dp) {
        if(i == str.size()) return 1;
        if(dp[i][tight][flag][prev] != -1) return dp[i][tight][flag][prev];
        int limit = (tight == 1 ? str[i] - '0' : 9);
        int ans = 0;
        for(int j = 0; j <= limit; j++) {
            if(flag == 0) {
                if(j == 0) ans += fun(i + 1, (tight && (str[i] - '0' == j)), 0, j, str, dp);
                else {
                    ans += fun(i + 1, (tight && (str[i] - '0' == j)), 1, j, str, dp);
                }
            } else {
                if(abs(j - prev) == 1) {
                    ans += fun(i + 1, (tight && (str[i] - '0' == j)), 1, j, str, dp);
                }
            }
            ans %= MOD;
        }
        return dp[i][tight][flag][prev] = ans;
    }
    int countSteppingNumbers(string low, string high) {
        int a = 1;
        for(int i = 1; i < low.size(); i++) {
            if(abs(low[i] - low[i - 1]) != 1) {
                a = 0;
                break;
            }
        }
        vector<vector<vector<vector<long long>>>> dp1(high.size(), vector<vector<vector<long long>>> (2, vector<vector<long long>> (2, vector<long long> (10, -1))));
        vector<vector<vector<vector<long long>>>> dp2(low.size(), vector<vector<vector<long long>>> (2, vector<vector<long long>> (2, vector<long long> (10, -1))));
        return (a + fun(0, 1, 0, 0, high, dp1) - fun(0, 1, 0, 0,low, dp2) + MOD) % MOD;
    }
};