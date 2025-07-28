class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> dp;
        int mx = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(dp.find(arr[i] - diff) != dp.end()) {
                dp[arr[i]] = 1 + dp[arr[i] - diff];
            } else dp[arr[i]] = 1;
            mx = max(dp[arr[i]], mx);
        }
        return mx;
    }
};