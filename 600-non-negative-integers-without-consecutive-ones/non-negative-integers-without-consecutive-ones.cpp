class Solution {
public:
    int fun(int i, int tight, int cnt, string& str, int dp[32][2][2]) {
        if(cnt > 1) return 0;
        if(i == str.size()) return 1;
        if(dp[i][tight][cnt] != -1) return dp[i][tight][cnt];
        int limit = (tight ? str[i] - '0' : 1);
        int ans = 0;
        for(int j = 0; j <= limit; j++) {
            ans += fun(i + 1, (tight && (str[i] - '0' == j)), (j == 1 ? cnt + 1 : 0), str, dp);
        }
        return dp[i][tight][cnt] = ans;
    }
    int findIntegers(int n) {
        int dp[32][2][2];
        memset(dp, -1, sizeof(dp));
        string bin = "";
        while(n) {
            bin += (n % 2) + '0';
            n /= 2;
        }
        reverse(bin.begin(), bin.end());
        return fun(0, 1, 0, bin, dp);
    }
};