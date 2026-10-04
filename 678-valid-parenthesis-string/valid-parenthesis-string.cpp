class Solution {
public:
    bool fun(int i, int cnt, string& s, vector<vector<int>>& dp) {
        int n = s.size();
        if(cnt < 0) return false;
        if(i == n) return cnt == 0;
        if(dp[i][cnt] != -1) return dp[i][cnt];
        int ans = 0;
        if(s[i] == '(') {
            ans = ans || fun(i + 1, cnt + 1, s, dp);
        } else if(s[i] == ')') {
            ans = ans || fun(i + 1, cnt - 1, s, dp);
        } else {
            ans = ans || fun(i + 1, cnt + 1, s, dp);
            ans = ans || fun(i + 1, cnt - 1, s, dp);
            ans = ans || fun(i + 1, cnt, s, dp);
        }
        return dp[i][cnt] = ans;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(0, 0, s, dp);
    }
};