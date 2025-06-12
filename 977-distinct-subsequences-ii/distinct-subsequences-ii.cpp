class Solution {
public:
    int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> dp(n + 1);
        dp[0] = 1;
        vector<int> last(26, -1);
        for(int i = 1; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2) % MOD;
            int ch = s[i - 1] - 97;
            if(last[ch] != -1) {
                dp[i] =  (dp[i] - dp[last[ch]] + MOD) % MOD;
            }
            last[ch] = i - 1;
        }
        
        return (dp[n] - 1 + MOD) % MOD;
    }
};