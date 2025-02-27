class Solution {
public:
    int fun(vector<int>& arr, int j, int k, unordered_map<int, int>& m, vector<vector<int>>& dp) {
        if(m.find(arr[k] - arr[j]) == m.end()) return 0;
        if(m[arr[k] - arr[j]] >= j) return 0;
        if(dp[j][k] != -1) return dp[j][k];
        return dp[j][k] =  1 + fun(arr, m[arr[k] - arr[j]], j, m, dp);
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int mx = 0;
        unordered_map<int, int> m;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1)); 
        for(int i = 0; i  < n; i++) m[arr[i]] = i;
        for(int k = n - 1; k >= 0; k--) {
            for(int j = k - 1; j > 0; j--) {
                int count = 2 + fun(arr, j, k, m, dp);
                mx = max(mx, count);
            }
        }
        if(mx == 2) return 0;
        return mx;
    }
};