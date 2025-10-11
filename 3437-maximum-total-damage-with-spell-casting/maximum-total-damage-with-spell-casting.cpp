class Solution {
public:
    long long fun(int i, vector<int>& power, vector<long long>& dp) {
        int n = power.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int idx = upper_bound(power.begin(), power.end(), power[i] + 2) - power.begin();
        long long count = upper_bound(power.begin(), power.end(), power[i]) - power.begin() - i;
        long long a = count * power[i] + fun(idx, power, dp);
        long long b = fun(i + 1, power, dp);
        return dp[i] = max(a, b);
    }
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        int n = power.size();
        vector<long long> dp(n, -1);
        return fun(0, power, dp);
    }
};