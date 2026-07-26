class Solution {
public:
    int MOD = 1e9 + 7;
    long long power(int a, int b) {
        if(b == 0) return 1;
        long long half = power(a, b / 2);
        if(b % 2) return half * half % MOD * a % MOD;
        return half * half % MOD;
    }
    long long ncr(int n, int r, vector<long long>& fact) {
        return fact[n] * power(fact[r] * fact[(n - r)] % MOD, MOD - 2) % MOD;
    }
    int countValidSequences(int n, int k) {
        vector<long long> fact(n + 1);
        fact[0] = 1;
        for(int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        int tot = ncr(n - 1, k - 1, fact);
        if((n - k) % 2 == 0) {
            int m = (n - k) / 2;
            tot -= ncr(m + k - 1, k - 1, fact);
        }
        return (tot + MOD) % MOD;
    }
};