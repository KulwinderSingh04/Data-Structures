class Solution {
public:
    int fun(int i, int tight, int even, int odd, int flag, int rem, int k, string str, int dp[11][2][11][11][2][20]) {
        if(i == str.size()) return rem == 0 && even == odd;
        if(dp[i][tight][even][odd][flag][rem] != -1) return dp[i][tight][even][odd][flag][rem];
        int limit = (tight ? str[i] - '0' : 9);
        int ans = 0;
        for(int j = 0; j <= limit; j++) {
            if(flag == 0) {
                if(j == 0) {
                    ans += fun(i + 1, (tight && (str[i] - '0' == j)), even, odd, 0, rem, k, str, dp);
                } else {
                    ans += fun(i + 1, (tight && (str[i] - '0' == j)), (j % 2 ? even : even + 1), (j % 2 ? odd + 1 : odd), 1, j, k, str, dp);
                }
            } else {
                ans += fun(i + 1, (tight && (str[i] - '0' == j)), (j % 2 ? even : even + 1), (j % 2 ? odd + 1 : odd), 1, (rem * 10 + j) % k, k, str, dp);
            }
        }
        return dp[i][tight][even][odd][flag][rem] = ans;
    } 
    int numberOfBeautifulIntegers(int low, int high, int k) {
        int dp1[11][2][11][11][2][20];
        int dp2[11][2][11][11][2][20];
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        int a = 0;
        string t = to_string(low);
        int m = 0;
        for(auto x : t) {
            if(x % 2) m++;
            else m--;
        }
        if(m == 0 && low % k == 0) a++;
        string s1 = to_string(high);
        string s2 = to_string(low);
        return a + fun(0, 1, 0, 0, 0, 0, k, s1, dp1) - fun(0, 1, 0, 0, 0, 0, k, s2, dp2);
    }
};