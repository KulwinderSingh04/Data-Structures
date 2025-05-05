class Solution {
public:
    int fun(int i, int currRate, vector<int>& position, vector<int>& time, int k, vector<vector<vector<int>>>& dp) {
        int n = time.size();
        if(dp[i][currRate][k] != -1) return dp[i][currRate][k];
        if(i == n - 1) {
            if(k > 0) return 1e9;
            return 0;
        }
        int res = INT_MAX;
        int t = fun(i + 1, time[i + 1], position, time, k, dp);
        res= min(res, (position[i + 1] - position[i]) * currRate + t);
        if(k != 0 ) {
            int mergeTime = time[i + 1];
            int mergeCount = 0;
            for(int idx = i + 2; idx < n && mergeCount < k; idx++) {
                mergeCount++;
                mergeTime += time[idx];
                int solve = fun(idx, mergeTime, position, time, k - mergeCount, dp);
                int dis = position[idx] - position[i];
                int a = dis * currRate;
                res = min(res, a + solve);
            }
        }
        return dp[i][currRate][k] = res;
    }
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        int sum = 0;
        for(int i = 0; i < n; i++) sum += time[i];
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (sum + 1, vector<int> (k + 1, -1)));
        return fun(0, time[0], position, time, k, dp);
    }
};