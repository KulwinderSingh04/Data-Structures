class Solution {
public:
    bool fun(int idx, string& s, unordered_set<string>& dict, vector<int>& dp) {
        int n = s.size();
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int i = idx; i < s.size(); i++) {
            string a = s.substr(idx, i - idx + 1);
            if(dict.find(a) != dict.end()) {
                bool f = fun(i + 1, s, dict, dp);
                if(f) return dp[idx] = f;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for(auto x : wordDict) dict.insert(x);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < s.size(); j++) {
                string a = s.substr(i, j - i + 1);
                if(dict.find(a) != dict.end()) {
                    bool f = dp[j + 1];
                    if(f) dp[i] = f;
                }
            }
        }
        return dp[0];
    }
};