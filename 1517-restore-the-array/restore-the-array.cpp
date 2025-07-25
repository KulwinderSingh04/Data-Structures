class Solution {
public:
    int MOD = 1e9+7;
    long long fun(int idx, string& s, int k, vector<int>& dp) {
        int n = s.size();
        if(idx == n) return 1;
        if(dp[idx] != -1) return dp[idx];
        long long res = 0;
        long long num = 0;
        for(int i = idx; i < n; i++) {
            num = num * 10 + (s[i] - 48);
            if(num > k) break;
            if(i + 1 < n && s[i + 1] == '0') continue;
            if(num >= 1 && num <= k) {
                res += fun(i + 1, s, k, dp);
                res %= MOD;
            }
        }
        return dp[idx] = res;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n, -1);
        return fun(0, s, k, dp);
    }
};