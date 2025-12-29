class Solution {
public:
    bool fun(string& str, unordered_map<string, vector<char>>& mp, unordered_map<string, bool>& dp) {
        if(str.size() == 1) return true;
        if(dp.find(str) != dp.end()) return dp[str];
        vector<string> v;
        for(int i = 0; i < str.size() - 1; i++) {
            string temp = "";
            temp.push_back(str[i]);
            temp.push_back(str[i + 1]);
            vector<string> nv;
            for(auto x : mp[temp]) {
                for(auto y : v) {
                    nv.push_back(y + x);
                }
                if(v.size() == 0) {
                    string J = "";
                    J.push_back(x);
                    nv.push_back(J);
                }
            }
            if(mp[temp].size() == 0) {
                return false;
            }
            v = nv;
        }
        for(auto x : v) {
            bool ans = fun(x, mp, dp);
            if(ans) return dp[str] = true;
        }
        return dp[str] = false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for(auto x : allowed) {
            char ch = x.back();
            x.pop_back();
            mp[x].push_back(ch);
        }
        unordered_map<string, bool> dp;
        return fun(bottom, mp, dp);
    }
};