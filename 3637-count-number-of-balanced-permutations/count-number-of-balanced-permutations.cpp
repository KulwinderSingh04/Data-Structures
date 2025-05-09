class Solution {
public:
    int MOD = 1e9+7;
    long long modInverse(long long a, int MOD) {
        long long res = 1, b = MOD - 2;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    long long fun(string& num, int i, int count, int sum, int& totSum, vector<long long>& fact, vector<vector<vector<long long>>>& dp) {
        int n = num.size();
        if(count == 0) {
            if(sum == (totSum - sum)) {
                return (fact[n / 2] * fact[n - n / 2]) % MOD;
            }
            return 0;
        }
        if(i == n) return 0;
        if(dp[i][count][sum] != -1) return dp[i][count][sum];
        long long pick = fun(num, i + 1, count - 1, sum + (num[i] - 48), totSum, fact, dp);
        long long np = fun(num, i + 1, count, sum, totSum, fact, dp);
        pick %= MOD;
        np %= MOD;
        return dp[i][count][sum] = ((np + pick) % MOD);
    }
    int countBalancedPermutations(string num) {
        int n = num.size();
        int totSum = 0;
        vector<long long> fact(n + 1, 1);
        for(int i = 1; i < n + 1; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;
        unordered_map<char, int> m;
        for(auto x : num) {
            m[x]++;
        }
        for(int i = 0; i < n; i++) totSum += (num[i] - 48);
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> ((n + 1) / 2 + 1, vector<long long> (totSum + 1, -1)));
        long long t = fun(num, 0, (n + 1) / 2, 0, totSum, fact, dp) % MOD;
        for(auto x : m) {
            t = (t * modInverse(fact[x.second], MOD)) % MOD;
        }
        return t % MOD;
    }
};