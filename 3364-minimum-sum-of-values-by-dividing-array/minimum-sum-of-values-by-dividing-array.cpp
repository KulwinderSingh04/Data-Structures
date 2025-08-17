class Solution {
public:
    int fun(int i, int k, int andVal, vector<int>& nums, vector<int>& andValues, vector<vector<unordered_map<int, int>>>& dp) {
        int n = nums.size();
        int m = andValues.size();
        if(i == n) return k == m ? 0 : 1e8;
        if(k >= m) return 1e8;
        if(dp[i][k].find(andVal) != dp[i][k].end()) return dp[i][k][andVal];
        int res = 1e8;
        if((andVal & nums[i]) == andValues[k]) {
            res = min(res, nums[i] + fun(i + 1, k + 1, INT_MAX, nums, andValues, dp));
        }
        res = min(res, fun(i + 1, k, andVal & nums[i], nums, andValues, dp));
        return dp[i][k][andVal] = res;

    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size();
        vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>> (10));
        int t = fun(0, 0, INT_MAX, nums, andValues, dp);
        return t == 1e8 ? -1 : t;
    }
};