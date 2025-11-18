class Solution {
public:
    int fun(int i, int tight, int mask, int flag, string& str, vector<vector<vector<vector<int>>>>& dp) {
        if(i == str.size()) return flag == 0;
        if(dp[i][tight][mask][flag] != -1) return dp[i][tight][mask][flag];
        int limit = (tight == 1 ? str[i] - '0' : 9);
        int ans = 0;
        for(int j = 0; j <= limit; j++) {
            if(j == 0 && flag) {
                    ans += fun(i + 1, (tight && (str[i] - '0' == j)), mask, 1, str, dp);
            } else {
                if((mask & (1 << j)) == 0) {
                    int newMask = mask | (1 << j);
                    ans += fun(i + 1, (tight && (str[i] - '0' == j)), newMask, 0, str, dp);
                }
            }
        }
        return dp[i][tight][mask][flag] = ans;
    }
    int countSpecialNumbers(int n) {
        string str = to_string(n);
        vector<vector<vector<vector<int>>>> dp(str.size(), vector<vector<vector<int>>> (2, vector<vector<int>> (2049, vector<int> (2, -1))));
        return fun(0, 1, 0, 1, str, dp);
    }
};