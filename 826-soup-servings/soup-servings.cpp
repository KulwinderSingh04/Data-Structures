class Solution {
public:
    vector<vector<int>> dir = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    double fun(int n1, int n2, unordered_map<string, double>& dp) {
        if(n1 <= 0 && n2 <= 0) return 0.5;
        if(n1 <= 0) return 1;
        if(n2 <= 0) return 0;
        string str = to_string(n1) + '_' + to_string(n2);
        if(dp.find(str) != dp.end()) return dp[str];
        double ans = 0;
        for(int i = 0; i < 4; i++) {
            ans += fun(n1 - dir[i][0], n2 - dir[i][1], dp);
        }
        return dp[str] = 0.25 * ans;
    }
    double soupServings(int n) {
        if(n >= 4800) return 1;
        unordered_map<string, double> dp;
        return fun(n, n,dp);
    }
};