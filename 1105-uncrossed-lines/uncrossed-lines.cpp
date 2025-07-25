class Solution {
public:
    int fun(int i1, int i2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(i1 == n1 || i2 == n2) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        int p = 0;
        if(nums1[i1] == nums2[i2]) p = 1 + fun(i1 + 1, i2 + 1, nums1, nums2, dp);
        int np = max(fun(i1 + 1, i2, nums1, nums2, dp), fun(i1, i2 + 1, nums1, nums2, dp));
        return dp[i1][i2] = max(np, p);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(), -1));
        return fun(0, 0, nums1, nums2, dp);
    }
};