class Solution {
public:
    int MOD = 1e9 + 7;
    long long fun(int i, int tight, int prev, int k, string& s, vector<vector<vector<long long>>>& dp) {
        if(i == s.size()) return 1;
        int limit = tight ? s[i] - '0' : 9;
        if(dp[i][tight][prev] != -1) return dp[i][tight][prev];
        long long ans = 0;
        for(int j = 0; j <= limit; j++) {
            if(prev == 10) {
                if(j == 0) {
                    ans = ans + fun(i + 1, tight && j + '0' == s[i], prev, k, s, dp);
                    // ans %= MOD;
                } else  {
                    ans = ans + fun(i + 1, tight && j + '0' == s[i], j, k, s, dp);
                    // ans %= MOD;
                }
            } else if(abs(prev - j) <= k) {
                ans = ans + fun(i + 1, tight && j + '0' == s[i], j, k, s, dp);
                // ans %= MOD;
            }
        }
        return dp[i][tight][prev] = ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        l--;
        string s1 = to_string(l);
        string s2 = to_string(r);
        vector<vector<vector<long long>>> dp1(17, vector<vector<long long>> (2, vector<long long> (11, -1)));
        vector<vector<vector<long long>>> dp2(17, vector<vector<long long>> (2, vector<long long> (11, -1)));
        return fun(0, 1, 10, k, s2, dp1) - fun(0, 1, 10, k, s1, dp2);
    }
};