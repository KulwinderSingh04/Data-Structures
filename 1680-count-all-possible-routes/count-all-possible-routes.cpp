class Solution {
public:
    int MOD = 1e9+7;
    int fun(int i, int fuel, int& end, vector<int>& loc, vector<vector<int>>& dp) {
        int n = loc.size();
        // if(i == end) return 1 +;
        if(dp[i][fuel] != -1) return dp[i][fuel];
        long long ans = 0;
        if(i == end) ans = 1;
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            if(fuel - abs(loc[i] - loc[j]) >= 0) ans += fun(j, fuel - abs(loc[i] - loc[j]), end, loc, dp);
            ans %= MOD;
        }
        return dp[i][fuel] = ans;
    }
    int countRoutes(vector<int>& loc, int start, int finish, int fuel) {
        int n = loc.size();
        vector<vector<int>> dp(n, vector<int> ( fuel + 1, -1));
        return fun(start, fuel, finish, loc, dp); 
    }
};