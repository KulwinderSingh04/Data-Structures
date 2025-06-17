class Solution {
public:
    bool fun(int idx, string& s, unordered_set<string>& st, vector<int>& dp) {
        if(idx == s.size()) {
            return true;
        }
        if(dp[idx] != -1) return dp[idx];
        bool t = false;
        for(int i = idx; i < s.size(); i++) {
            if(st.find(s.substr(idx, i - idx + 1)) != st.end()) {
                t = fun(i + 1, s, st, dp);
                if(t) break;
            }
        }
        return dp[idx] = t;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto x : wordDict) {
            st.insert(x);
        }
        int n = s.size();
        vector<int> dp(n, -1);
        return fun(0, s, st, dp);
    }
};