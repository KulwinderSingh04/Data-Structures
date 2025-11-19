class Solution {
public:
    // int fun(int i, int tight, int flag, int mask, string& str, vector<vector<vector<int>>>& dp) {
    //     if(i == str.size()) return flag != 0;
    //     int limit = (tight == 1 ? str[i] - '0' : 9);
    //     if(dp[i][tight][flag] != -1) return dp[i][tight][flag];
    //     int ans = 0;
    //     for(int j = 0; j <= limit; j++) {
    //         if((mask & (1 << j)) == 0) continue;
    //         if(j == 0 || j == 1 || j == 8) {
    //             ans += fun(i + 1, (tight && (str[i] - '0' == j)), flag, mask, str, dp);
    //         }
    //         else ans += fun(i + 1, (tight && (str[i] - '0' == j)), 1, mask, str, dp);
    //     }
    //     return dp[i][tight][flag] = ans;
    // }
    int rotatedDigits(int n) {
        // int mask = 871;
        // string str = to_string(n);
        // vector<vector<vector<int>>> dp(str.size(), vector<vector<int>> (2, vector<int> (2, -1)));
        // return fun(0, 1, 0, mask, str, dp);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            unordered_set<int> st;
            for(int j = 0; j < to_string(i).size(); j++) {
                st.insert(to_string(i)[j] - '0');
            }
            if(st.find(4) != st.end() || st.find(3) != st.end() || st.find(7) != st.end()) continue;
            if(st.find(2) != st.end() || st.find(5) != st.end() || st.find(6) != st.end() || st.find(9) != st.end()) ans++;
        }
        return ans;
    }
};