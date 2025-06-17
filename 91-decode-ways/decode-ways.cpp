class Solution {
public:
    int fun(int idx, string& s, vector<int>& dp) {
        int n = s.size();
        if(idx == n) {
            return 1;
        }
        if(dp[idx] != -1) return dp[idx];
        if(s[idx] == '0') return 0;
        int a = 0;
        for(int i = idx; i < min(n, idx + 2); i++) {
            int num = stoi(s.substr(idx, i - idx + 1));
            if(num >= 1 && num <= 26) a += fun(i + 1, s, dp);
        }
        return dp[idx] = a;
    }
    int numDecodings(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') return 0;
            else break;
        }
        vector<int> dp(n, -1);
        return fun(0, s, dp);
    }
};