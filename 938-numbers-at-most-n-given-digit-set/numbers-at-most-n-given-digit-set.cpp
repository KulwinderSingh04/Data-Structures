class Solution {
public:
    int fun(int i, int tight, int can, string& str, unordered_set<int>& st, vector<vector<vector<int>>>& dp) {
        if(i == str.size()) return can != 1;
        if(dp[i][tight][can] != -1) return dp[i][tight][can];
        int limit = (tight == 1 ? str[i] - '0' : 9);
        int ans = 0;
        for(int j = 0; j <= limit; j++) {
            if(j != 0 && st.find(j) == st.end()) continue;
            if(j == 0) {
                if(can) ans += fun(i + 1, (tight && str[i] - '0' == j), can, str, st, dp);
            }
            else ans += fun(i + 1, (tight && str[i] - '0' == j), 0, str, st, dp);
        }
        return dp[i][tight][can] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        unordered_set<int> st;
        for(auto x : digits) st.insert(stoi(x));
        string str = to_string(n);
        vector<vector<vector<int>>> dp(10, vector<vector<int>> (2, vector<int> (2, -1)));
        return fun(0, 1, 1, str, st, dp);
    }
};