class Solution {
public:
    int M = 1e9+7;
    void findSet(int m, vector<long long>& count, vector<vector<long long>>& dp) {
        if(dp[m][1] != 0) return;

        dp[m][1] = 1;
        count[1]++;
        for(int div = 2; div <= m; div++) {
            if(m % div == 0) {
                findSet(m / div, count, dp);
                for(int len = 1; len <= 14; len++) {
                    if(dp[m / div][len] != 0) {
                        dp[m][len + 1] += dp[m / div][len];
                        count[len + 1] += dp[m / div][len];
                    }
                }
            }
        }
    }

    int modularnCr(int n, int r, vector<long long>& fact) {
        if(r < 0 || r > n) return 0;
        long long b  = (fact[r] * fact[n - r]) % M;
        return fact[n] * pow(b, M - 2) % M;
    }

    long long pow(int a, int b) {
        if(b == 0) return 1;
        long long x = pow(a, b / 2);
        long long res = (x * x) % M;
        if(b % 2) return (a * res) % M;
        return res;
    }

    int idealArrays(int n, int maxValue) {
        vector<vector<long long>> dp(maxValue + 1, vector<long long> (15, 0));
        vector<long long> count(15, 0);
        for(int val = 1; val < maxValue + 1; val++) {
            findSet(val, count, dp);
        }

        vector<long long> fact(n + 1, 1);
        for(int i = 2; i < n + 1; i++) {
            fact[i] = (fact[i - 1] * i) % M;
        }

        long long res = 0;
        for(int len = 1; len < 15; len++) {
            int pos = modularnCr(n - 1, len - 1, fact);
            res = (res + (count[len] * pos) % M) % M;
        }
        return res;
    }
};