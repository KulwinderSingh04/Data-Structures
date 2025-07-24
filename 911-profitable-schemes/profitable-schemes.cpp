class Solution {
public:
    int MOD = 1e9+7;
    long long fun(int i, int n, int prof, int& minProfit, vector<int>& group, vector<int>& profit, vector<vector<vector<long long>>>& dp) {
        prof = min(prof, minProfit);
        if(i == group.size()) {
            return prof >= minProfit;
        }
        // cout << prof << " "; 
        if(dp[i][n][prof] != -1) return dp[i][n][prof];
        long long p = 0;
        if(n - group[i] >= 0) p = fun(i + 1, n - group[i], prof + profit[i], minProfit, group, profit, dp);
        long long np = fun(i + 1, n, prof, minProfit, group, profit, dp);
        return dp[i][n][prof] = (np % MOD + p % MOD) % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int sum = 0;
        for(auto x : profit) sum += x;
        // cout << sum << " ";
        vector<vector<vector<long long>>> dp(group.size(), vector<vector<long long>> (n + 1, vector<long long> (minProfit + 1, -1)));
        return fun(0, n, 0, minProfit, group, profit, dp);
    }
};