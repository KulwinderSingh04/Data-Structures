class Solution {
public:
    bool f(int num) {
        string s = to_string(num);
        int n = s.size();
        int inc = 1, dec = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] >= s[i - 1]) dec = false;
            if(s[i] <= s[i - 1]) inc = false;
        }
        return inc || dec;
    }
    long long fun(int i, int prev, int tight, int started, int inc, int dec, int sum, string& s, vector<int>& v, long long dp[19][10][2][2][2][2][150]) {
        if(i == s.size()) {
            if(!started) return 0;
            return inc || dec || v[sum];
        }
        int limit = tight == 1 ? s[i] : '9';
        if(prev != -1 && dp[i][prev][tight][started][inc][dec][sum] != -1) return dp[i][prev][tight][started][inc][dec][sum];
        long long ans = 0;
        for(int j = '0'; j <= limit; j++) {
            if(!started && j == '0') ans += fun(i + 1, -1, tight && s[i] == j, 0, 1, 1, 0, s, v, dp);
            else {
                ans += fun(i + 1, j - '0', tight && s[i] == j, 1, (prev == -1 || j > (prev + '0')) && inc, (prev == -1 || j < prev + '0') && dec, sum + j - '0', s, v, dp);
            }
        }
        if(prev == -1) return ans;
        return dp[i][prev][tight][started][inc][dec][sum] = ans;
    }
    long long countFancy(long long l, long long r) {
        vector<int> v(150);
        for(int i = 0; i < 150; i++) v[i] = f(i);
        string s1 = to_string(l - 1);
        string s2 = to_string(r);
        long long dp1[19][10][2][2][2][2][150];
        long long dp2[19][10][2][2][2][2][150];
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        return fun(0, -1, 1, 0, 1, 1, 0, s2, v, dp1) - fun(0, -1, 1, 0, 1, 1, 0, s1, v, dp2);
    }
};