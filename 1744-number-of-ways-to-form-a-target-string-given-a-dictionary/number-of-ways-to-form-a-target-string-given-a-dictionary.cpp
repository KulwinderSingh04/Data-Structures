class Solution {
public:
    int MOD = 1e9 + 7;
    long long fun(int i, int j, vector<string>& words, string& target, vector<vector<long long>>& freq, vector<vector<long long>>& dp) {
        if(i == target.size()) return 1;
        if(j == words[0].size())return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long p = freq[target[i] - 'a'][j] * fun(i + 1, j + 1, words, target, freq, dp);
        long long np = fun(i, j + 1, words, target, freq, dp);
        return dp[i][j] = (p % MOD + np % MOD) % MOD;

    }
    int numWays(vector<string>& words, string target) {
        vector<vector<long long>> freq(26, vector<long long> (words[0].size()));
        vector<vector<long long>> dp(target.size(), vector<long long> (words[0].size(), -1));
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[0].size(); j++) {
                freq[words[i][j] - 'a'][j]++;
            }
        }
        return fun(0, 0, words, target, freq, dp);
    }
};