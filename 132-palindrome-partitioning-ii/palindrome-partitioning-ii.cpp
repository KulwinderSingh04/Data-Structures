class Solution {
public:
    bool isPal(string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    // int fun(int idx, string& s, vector<int>& dp) {
    //     int n = s.size();
    //     if(idx == n) return 1;
    //     if(dp[idx] != -1) return dp[idx];
    //     int mn = INT_MAX;
    //     for(int i = idx; i < n; i++) {
    //         // string str = s.substr(idx, i - idx + 1);
    //         // cout << str << endl;
    //         if(isPal(s, idx, i)) {
    //             mn = min(mn, 1 + fun(i + 1, s, dp));
    //         }
    //     }
    //     return dp[idx] = mn;
    // }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--) {
            int mn = INT_MAX;
            for(int k = i; k < n; k++) {
                if(isPal(s, i, k)) {
                    mn = min(mn, 1 + dp[k + 1]);
                }
            }
            dp[i] = mn;
        }
        return dp[0] - 1;
    }
};