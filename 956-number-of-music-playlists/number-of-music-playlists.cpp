class Solution {
public:
    int MOD = 1e9+7;
    int fun(int count_songs, int count_unique, int n, int goal, int k, vector<vector<int>>& dp) {
        if(count_songs == goal) {
            return count_unique == n;
        }
        if(dp[count_songs][count_unique] != -1) return dp[count_songs][count_unique];
        long long res = 0;
        if(count_unique < n) res += 1LL * (n - count_unique) * fun(count_songs + 1, count_unique + 1, n, goal, k, dp);
        if(count_unique > k) res += 1LL * (count_unique - k) * fun(count_songs + 1, count_unique, n, goal, k, dp);
        return dp[count_songs][count_unique] = res % MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(goal, vector<int> (n + 1, -1));
        return fun(0, 0, n, goal, k, dp);
    }
};