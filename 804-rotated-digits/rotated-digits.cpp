class Solution {
public:
    int fun(int i, int tight, int flag, int mask, string& str, vector<vector<vector<int>>>& dp) {
        if(i == str.size()) return flag != 0;
        int limit = (tight == 1 ? str[i] - '0' : 9);
        if(dp[i][tight][flag] != -1) return dp[i][tight][flag];
        int ans = 0;
        for(int j = 0; j <= limit; j++) {
            if((mask & (1 << j)) == 0) continue;
            if(j == 0 || j == 1 || j == 8) {
                ans += fun(i + 1, (tight && (str[i] - '0' == j)), flag, mask, str, dp);
            }
            else ans += fun(i + 1, (tight && (str[i] - '0' == j)), 1, mask, str, dp);
        }
        return dp[i][tight][flag] = ans;
    }
    int rotatedDigits(int n) {
        int mask = 871;
        // mask = mask | (1 << 0);
        // mask = mask | (1 << 1);
        // mask = mask | (1 << 8);
        // mask = mask | (1 << 2);
        // mask = mask | (1 << 5);
        // mask = mask | (1 << 6);
        // mask = mask | (1 << 9);
        string str = to_string(n);
        vector<vector<vector<int>>> dp(str.size(), vector<vector<int>> (2, vector<int> (2, -1)));
        return fun(0, 1, 0, mask, str, dp);

    }
};