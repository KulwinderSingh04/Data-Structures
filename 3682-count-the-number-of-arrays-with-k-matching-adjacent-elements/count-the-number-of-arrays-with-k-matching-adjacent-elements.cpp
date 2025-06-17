class Solution {
public:
    int MOD = 1e9 + 7;

    long long pow(long long a, long long b) {
        if(b == 0) return 1;
        long long half = pow(a, b / 2) % MOD;
        half = (half * half) % MOD;
        if(b % 2 == 0) return half;
        return (a * half) % MOD;
    }

    long long fact(int a) {
        long long ans = 1;
        for(int i = 1; i <= a; i++) {
            ans = (ans * i) % MOD;
        }
        return ans;
    }

    long long modularNcR(int n, int r) {
        if(r < 0 || r > n) return 0;
        long long a = fact(n);
        long long b = (fact(r) * fact(n - r)) % MOD;
        return (a * pow(b, MOD - 2)) % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        if(k > n - 1) return 0;
        long long ans = pow(m - 1, n - 1 - k);
        long long t = modularNcR(n - 1, k);
        return (ans * m % MOD * t % MOD) % MOD;
    }
};
