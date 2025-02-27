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
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 2)); 
        for(int i = 0; i  < n; i++) m[arr[i]] = i;
        for(int j = 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(m.find(arr[k] - arr[j]) != m.end() && m[arr[k] - arr[j]] < j) dp[j][k] = 1 + dp[m[arr[k] - arr[j]]][j];
                mx = max(mx, dp[j][k]);
            }
        }
        if(mx == 2) return 0;
        return mx;
    }
};