class Solution {
public:
    int fun(int stair, int jump, int flag, int k, unordered_map<string, int>& dp) {
        if(stair > k + 1) return 0;
        if(stair < 0) return 0;
        string str = to_string(stair) + ',' + to_string(jump) + ',' +to_string(flag);
        if(dp.find(str) != dp.end()) return dp[str];
        int p = 0;
        p = fun(stair + pow(2, jump), jump + 1, 0, k, dp);

        int np = 0;
        if(flag == 0) np = fun(stair - 1, jump, 1, k, dp);
        return dp[str] = stair == k ? 1 + np + p : np + p;
    }
    int waysToReachStair(int k) {
        unordered_map<string, int> dp;
        return fun(1, 0, 0, k, dp);
    }
};