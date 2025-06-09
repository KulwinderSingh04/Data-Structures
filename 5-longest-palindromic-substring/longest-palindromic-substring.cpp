class Solution {
public:
    bool isPal(string& s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int fun(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i >= j) return s[i] == s[j];
        if(dp[i][j] != -1) return dp[i][j];
        if(isPal(s, i, j)) return dp[i][j] = j - i + 1;
        else {
            int a = fun(i + 1, j, s, dp);
            int b = fun(i, j - 1, s, dp);
            return dp[i][j] = max(a, b);
        }
        
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int sz = fun(0, n - 1, s, dp
        );
        for(int i = 0; i <= n - sz; i++) {
            if(isPal(s, i, i + sz - 1)) return s.substr(i, sz);
        }
        return "";
    }
};