class Solution {
public:
    int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        unordered_map<int, int> mp;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            mn = min(mn, complexity[i]);
            mp[complexity[i]]++;
        }
        if(mp[complexity[0]] > 1 || mn != complexity[0]) return 0;
        vector<long long> fact(n + 1);
        fact[0] = 1;
        for(int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= MOD;
        }
        mp[complexity[0]]--;
        if(mp[complexity[0]] == 0) mp.erase(complexity[0]);
        long long num = fact[n - 1];
        // long long deno = 1;
        // for(auto x : mp) {
        //     deno *= fact[x.second];
        //     deno %= MOD;
        // }
        return num;
    }
};