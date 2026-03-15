class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        vector<int> pref(n, 2);
        for(int i = 2; i < n; i++) {
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) pref[i] = pref[i - 1] + 1;
        }
        vector<int> suff(n, 2);
        for(int i = n - 3; i >= 0; i--) {
            if(nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]) suff[i] = suff[i + 1] + 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, max(suff[i] + 1, pref[i] + 1));
        }

        ans = min(n, ans);
        for(int i = 1; i < n - 1; i++) {
            long long diff = nums[i + 1] - nums[i - 1];
            if(diff % 2 == 0) {
                diff /= 2;
                int l = 1;
                int r = 1;
                if(i >= 2 && (nums[i - 1] - nums[i - 2]) == diff) l = pref[i - 1];
                if(i <= n - 3 && (nums[i + 2] - nums[i + 1]) == diff) r = suff[i + 1];
                ans = max(l + r + 1, ans);
            }
        }
        return ans;
    }
};