class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n), suff(n);
        pref[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] | nums[i];
        }
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] | nums[i];
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int leftOr = 0, rightOr = 0;
            if(i > 0) leftOr = pref[i - 1];
            if(i < n - 1) rightOr = suff[i + 1];
            ans = max(ans, leftOr | rightOr | ( 1LL * nums[i] << k));
        }
        return ans;
    }
};