class Solution {
public:
    int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int c = 0;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            mn = min(mn, complexity[i]);
            if(complexity[i] == complexity[0]) c++;
        }
        if(c > 1 || mn != complexity[0]) return 0;
        vector<long long> fact(n);
        fact[0] = 1;
        for(int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= MOD;
        }
        return fact[n - 1];
    }
};