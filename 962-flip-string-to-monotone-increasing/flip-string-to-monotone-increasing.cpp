class Solution {
public:
    // int fun(int i, int flag, string& s, vector<vector<int>>& dp) {
    //     int n = s.size();
    //     if(flag) {
    //         int ans = 0;
    //         for(int j = i; j < n; j++) ans += s[j] == '0';
    //         return ans;
    //     }
    //     if(i == n) return 0;
    //     if(dp[i][flag] != -1) return dp[i][flag];
    //     if(s[i] == '1') {
    //         int p = 1 + fun(i + 1, 0, s, dp);
    //         int np = fun(i + 1, 1, s, dp);
    //         return dp[i][flag] = min(np, p);
    //     } else {
    //         int p = 1 + fun(i + 1, 1, s, dp);
    //         int np = fun(i + 1, 0, s, dp);
    //         return dp[i][flag] = min(np, p);
    //     }

    // }
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        // vector<vector<int>> dp(n, vector<int> (2, -1));
        // return fun(0, 0, s, dp);
        vector<int> pref(n), suff(n);
        pref[0] = (s[0] == '1');
        int c1 = (s[0] == '1');
        int c2 = (s[0] == '0');
        for(int i = 1; i < n; i++) {
            c1 += s[i] == '1';
            c2 += s[i] == '0';
            pref[i] = pref[i - 1] + (s[i] == '1');
        }
        suff[n - 1] = (s[n - 1] == '0');
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + (s[i] == '0');
        }
        int ans = INT_MAX;
        // for(auto x : pref) cout << x << " ";
        // cout << endl;
        // for(auto x : suff) cout << x << " ";
        for(int i = 0; i < n - 1; i++) {
            ans = min(ans, pref[i] + suff[i + 1]); 
        }
        if(c1 == n || c2 == n) return 0;
        return min(ans, min(pref[n - 1], suff[0]));
    }
};