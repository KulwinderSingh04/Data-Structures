class Solution {
public:
    long long MOD = 1e9+7;
    long long fun(int i, int tight, int sum, string& str, int& min_sum, int& max_sum, vector<vector<vector<long long>>>& dp) {
        if(sum > max_sum) return 0;
        if(i == str.size()) return sum >= min_sum;
        if(dp[i][tight][sum] != -1) return dp[i][tight][sum];
        int limit = (tight == 1 ? str[i] - '0' : 9);
        long long ans = 0;
        for(int j = 0; j <= limit; j++) {
            ans = (ans + fun(i + 1, (tight && (str[i] - '0' == j)), sum + j, str, min_sum, max_sum, dp)) % MOD;
        }
        return dp[i][tight][sum] = ans % MOD;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        long long ans = 0;
        long long sum = 0;
        for(int i = 0; i < num1.size(); i++) sum += (num1[i] - '0');
        if(sum >= min_sum && sum <= max_sum) ans = 1;
        vector<vector<vector<long long>>> dp1(num2.size(), vector<vector<long long>>(2, vector<long long> (max_sum + 1, -1)));
        vector<vector<vector<long long>>> dp2(num1.size(), vector<vector<long long>>(2, vector<long long> (max_sum + 1, -1)));
        // return fun(0, 1, 0, num1, min_sum, max_sum, dp);
        return ans + (fun(0, 1, 0, num2, min_sum, max_sum, dp1) - fun(0, 1, 0, num1, min_sum, max_sum, dp2) + MOD) % MOD;
    }
};