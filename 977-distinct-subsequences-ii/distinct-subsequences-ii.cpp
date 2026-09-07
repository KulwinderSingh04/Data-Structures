class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        vector<int> dp(n);
        dp[0] = 2;
        last[s[0] - 'a'] = 0;
        int MOD = 1e9 + 7;
        for(int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] * 2 % MOD;
            int ch = s[i] - 'a';
            if(last[ch] != -1) {
                int prev = last[ch];
                if(prev == 0) dp[i] = (dp[i] - 1 + MOD) % MOD;
                else dp[i] = (dp[i] - dp[prev - 1] + MOD) % MOD;
            }
            last[ch] = i;
        }
        return (dp[n - 1] - 1 + MOD) % MOD;
    }
};