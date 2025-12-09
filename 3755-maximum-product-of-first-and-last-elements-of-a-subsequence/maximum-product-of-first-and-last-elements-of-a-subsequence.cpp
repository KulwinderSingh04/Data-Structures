class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> pos(n), neg(n);
        int mn = INT_MAX, mx = INT_MIN;
        long long ans = LLONG_MIN;
        for(int i = n - 1; i >= 0; i--) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
            pos[i] = mx;
            neg[i] = mn;
        }
        for(int i = 0; i < n - m + 1; i++) {
            if(nums[i] < 0) {
                ans = max(ans, 1LL * neg[i + m - 1] * nums[i]);
            } else {
                ans = max(ans, 1LL * pos[i + m - 1] * nums[i]);
            }
        }
        return ans;

    }
};