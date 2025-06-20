class Solution {
public:
    int binSearch(int time, int lo, int hi, vector<vector<int>>& arr) {
        int res = hi + 2;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(arr[mid][0] >= time) {
                res = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return res;
    }
    int fun(int i,vector<vector<int>>& arr, vector<int>& dp) {
        int n = arr.size();
        if(i >= n) return 0;
        int a = 0;
        if(dp[i] != -1) return dp[i];
        int idx = binSearch(arr[i][1], i + 1, n - 1, arr);
        a = arr[i][2] + fun(idx, arr, dp);
        int b = fun(i + 1, arr, dp);
        return dp[i] = max(a, b);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = endTime.size();
        vector<int> dp(n, -1);
        vector<vector<int>> arr(n);
        for(int i = 0; i < n; i++) arr[i] = {startTime[i], endTime[i], profit[i]};
        sort(arr.begin(), arr.end());
        return fun(0, arr, dp);
    }
};