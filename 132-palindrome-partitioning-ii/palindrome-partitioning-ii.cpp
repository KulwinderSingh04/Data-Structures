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
    int fun(int idx, string& s, vector<int>& dp) {
        int n = s.size();
        if(idx == n) return 1;
        if(dp[idx] != -1) return dp[idx];
        int mn = INT_MAX;
        for(int i = idx; i < n; i++) {
            // string str = s.substr(idx, i - idx + 1);
            // cout << str << endl;
            if(isPal(s, idx, i)) {
                mn = min(mn, 1 + fun(i + 1, s, dp));
            }
        }
        cout << mn << " ";
        return dp[idx] = mn;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return fun(0, s, dp) - 2;
    }
};