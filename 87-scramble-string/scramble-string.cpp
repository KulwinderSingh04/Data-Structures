class Solution {
public:
    bool fun(string s1, string s2, unordered_map<string, bool>& dp) {
        if(s1.size() == 1) {
            return s1 == s2;
        } 
        string str = s1 + s2;
        if(dp.find(str) != dp.end()) return dp[str];
        int n = s1.size();
        for(int k = 0; k < n - 1; k++) {
            bool a = fun(s1.substr(0, k + 1), s2.substr(0, k + 1), dp) && fun(s1.substr(k + 1), s2.substr(k + 1), dp);
            bool b = fun(s1.substr(0, k + 1), s2.substr(n - k - 1), dp) && fun(s1.substr(k + 1), s2.substr(0, n - k - 1), dp);
            if(a || b) return dp[str] = true;
        }
        return dp[str] = false;
    }
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> dp;
        return fun(s1, s2, dp);
    }
};