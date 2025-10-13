class Solution {
public:
    int MOD = 1e9 + 7;
    vector<long long> fact, invFact;
    long long pow(long long a, long long b) {
        if(b == 0) return 1;
        long long x = pow(a, b / 2);
        if(b % 2) return (a * ((x * x) % MOD)) % MOD;
        return (x * x) % MOD;
    }
    long long nCrMod(int n, int r) {
        if(r < 0 || r > n) return 0;
        long long ans = (fact[n] * ((invFact[r] % MOD) * (invFact[n - r] % MOD) % MOD)) % MOD;
        return ans;
    }
    long long fun(int i, int m, long long binSum, vector<int>& nums, int k, unordered_map<string, long long>& dp) {
        int n = nums.size();
        if(m == 0) {
            return __builtin_popcount(binSum) == k;
        }
        if(i >= n) return 0;
        string str = to_string(i) + '_' + to_string(m) + '_' + to_string(binSum) + '_' + to_string(k);
        if(dp.find(str) != dp.end()) return dp[str];
        if(m < 0) return 0;
        long long res = 0;
        for(int freq = 1; freq <= m; freq++) {
            long long newBinSum = binSum + freq;
            long long prod = fun(i + 1, m - freq, newBinSum >> 1, nums, k - (newBinSum & 1), dp);
            prod = (prod * (pow(nums[i], freq) * nCrMod(m, freq) % MOD)) % MOD;
            res = (res + prod) % MOD;
        }
        long long ntake = fun(i + 1, m, binSum >> 1, nums, k - (binSum & 1), dp);
        res = (res + ntake) % MOD;
        return dp[str] = res % MOD;
    }
    int magicalSum(int m, int k, vector<int>& nums) {
        unordered_map<string, long long> dp;

        fact.resize(m + 1, 1);
        invFact.resize(m + 1, 1);
        for(int i = 2; i <= m; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        for(int i = 0; i <= m; i++) {
            invFact[i] = pow(fact[i], MOD - 2);
        }
        return fun(0, m, 0, nums, k, dp);
    }
};