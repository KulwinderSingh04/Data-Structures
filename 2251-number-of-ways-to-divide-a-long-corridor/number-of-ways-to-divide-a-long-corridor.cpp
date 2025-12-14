class Solution {
public:
    int MOD = 1e9 + 7;
    int fun(int i, int count, string& v, vector<vector<int>>& dp) {
        int n = v.size();
        if(i == n) return count == 2;
        if(count > 2) return 0;
        if(dp[i][count] != -1) return dp[i][count];
        long long a = 0;
        if(count == 2) a = fun(i + 1, v[i] == 'S', v, dp);
        long long b = fun(i + 1, count + (v[i] == 'S'), v, dp);
        return dp[i][count] = (a + b) % MOD;
    }
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> v(n);
        v[0] = (corridor[0] == 'S');
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return fun(0, 0, corridor, dp);
    }
};