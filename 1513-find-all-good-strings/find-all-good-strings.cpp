class Solution {
public:
    int MOD = 1e9 + 7;
    long long fun(int i, int tight, int j, string& s, string& evil, vector<int>& lps, vector<vector<vector<long long>>>& dp) {
        if(j == evil.size()) return 0;
        if(i == s.size()) {
            return 1;
        }
        if(dp[i][tight][j] != -1) return dp[i][tight][j];
        char limit = (tight == 1 ? s[i] : 'z');
        long long ans = 0;
        for(char k = 'a'; k <= limit; k++) {
            int nj = j;
            while (nj > 0 && evil[nj] != k) nj = lps[nj - 1];
            if (evil[nj] == k) nj++;
            ans += fun(i + 1, (tight && (s[i] == k)), nj, s, evil, lps, dp);
            ans %= MOD;
        }
        return dp[i][tight][j] = ans;
    }
    vector<int> buildLps(string &evil) {
        int n = evil.size();
        vector<int> v(n, 0);
        int len = 0;
        v[0] = 0;
        int i = 1;
        while(i < n) {
            if(evil[i] == evil[len]) {
                len++;
                v[i] = len;
                i++;
            } else {
                if(len == 0) {
                    i++;
                    v[i - 1] = 0;
                }
                else len = v[len - 1];
            }
        }
        return v;
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<int> lps = buildLps(evil);
        bool flag = true;
        int ans = 0;
        for(int i = 0; i < s1.size() - evil.size() + 1; i++) {
            if(s1.substr(i, evil.size()) == evil) {
                flag = false;
                break;
            }
        }
        if(flag) ans = 1;
        vector<vector<vector<long long>>> dp1(s1.size(), vector<vector<long long>> (2, vector<long long> (evil.size(), -1)));
        vector<vector<vector<long long>>> dp2(s2.size(), vector<vector<long long>> (2, vector<long long> (evil.size(), -1)));
        return ans + (fun(0, 1, 0, s2, evil, lps, dp1) - fun(0, 1, 0, s1, evil, lps, dp2) + MOD) % MOD;
    }
};