class Solution {
public:
    bool isPos(vector<int>& arr) {
        for(auto x : arr) {
            if(x < 0) return false;
        }
        return true;
    }
    bool isNeg(vector<int>& arr) {
        for(auto x : arr) {
            if(x > 0) return false;
        }
        return true;
    }
    int fun(int i1, int i2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(i1 == nums1.size()) return 0;
        if(i2 == nums2.size()) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        int res = INT_MIN;
        for(int j = i2; j < nums2.size(); j++) {
            res = max(res, nums1[i1] * nums2[j] + fun(i1 + 1, j + 1, nums1, nums2, dp));
        }
        res = max(res, fun(i1 + 1, i2, nums1, nums2, dp));
        return dp[i1][i2] = res;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        if(isPos(nums1) && isNeg(nums2)) {
            int mn1 = *min_element(nums1.begin(), nums1.end());
            int mn2 = *max_element(nums2.begin(), nums2.end());
            return mn1 * mn2;
        }
        if(isPos(nums2) && isNeg(nums1)) {
            int mn1 = *max_element(nums1.begin(), nums1.end());
            int mn2 = *min_element(nums2.begin(), nums2.end());
            return mn1 * mn2;
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return fun(0, 0, nums1, nums2, dp);
    }
};