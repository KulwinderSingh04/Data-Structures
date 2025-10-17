class Solution {
public:
    int setBits(int a) {
        return __builtin_popcount(a);
    }
    int fun(int i, int unique, bool canChange, string& s, int k, unordered_map<long long, int>& dp) {
        int n = s.size();
        if(i == n) return unique != 0;
        int nc = 0;
        long long num = (1LL * i << 27) | (unique << 1) | canChange;
        if(dp.find(num) != dp.end()) return dp[num];
        if(setBits(unique | (1 << (s[i] - 'a'))) > k) nc = 1 + fun(i + 1, (1 << (s[i] - 'a')), canChange, s, k, dp);
        else nc = fun(i + 1, unique | (1 << (s[i] - 'a')), canChange, s, k, dp);
        int mc = 0;
        if(!canChange) {
            for(int j = 0; j < 26; j++) {
                int c = 0;
                if(setBits(unique | (1 << j)) > k) c = 1 + fun(i + 1, (1 << j), true, s, k, dp);
                else c = fun(i + 1, unique | (1 << j), true, s, k, dp);
                mc = max(mc, c);
            }
        }
        return dp[num] = max(mc, nc);
    }
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, int> dp;
        return fun(0, 0, false, s, k, dp);
    }
};