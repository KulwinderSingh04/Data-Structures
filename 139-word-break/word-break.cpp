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
        vector<int> dp(n, -1);
        for(auto x : wordDict) dict.insert(x);
        return fun(0, s, dict, dp);
    }
};