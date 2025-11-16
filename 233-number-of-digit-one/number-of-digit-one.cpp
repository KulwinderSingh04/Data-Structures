class Solution {
public:
    int fun(string& str, int i, int tight, int cnt, vector<vector<vector<int>>>& dp) {
        if(i == str.size()) return cnt;
        int limit = (tight == 1 ? str[i] - '0' : 9);
        if(dp[i][tight][cnt] != -1) return dp[i][tight][cnt];
        int ans = 0;
        for(int j = 0; j <= limit; j++) {
            int newCnt = cnt + (j == 1 ? 1 : 0);
            ans += fun(str, i + 1, (tight && str[i] == j + '0'), newCnt, dp);
        }
        return dp[i][tight][cnt] = ans;
    }
    int countDigitOne(int n) {
        string str = to_string(n);
        vector<vector<vector<int>>> dp(10, vector<vector<int>> (2, vector<int> (20, -1)));
        return fun(str, 0, 1, 0, dp);
    }
};