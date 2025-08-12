class Solution {
public:
    int fun(int i, string& s, unordered_set<string>& dict, vector<int>& dp) {
        if(i == s.size()) return 0;
        int res = INT_MAX;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < s.size(); j++) {
            string str = s.substr(i, j - i + 1);
            if(dict.find(str) != dict.end()) {
                res = min(res, fun(j + 1, s, dict, dp));
            } else {
                res = min(res, (int)str.size() + fun(j + 1, s, dict, dp));
            }
        }
        return dp[i] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict;
        for(auto x : dictionary) dict.insert(x);
        int n = s.size();
        vector<int> dp(n, -1);
        return fun(0, s, dict, dp);
    }
};