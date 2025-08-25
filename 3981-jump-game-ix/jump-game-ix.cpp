class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suff(n);
        int mxIdx = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[mxIdx]) mxIdx = i;
            pref[i] = mxIdx;
        }
        int mnIdx = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] <= nums[mnIdx]) mnIdx = i;
            suff[i] = mnIdx;
        }
        vector<int> ans(n);
        ans[n - 1] = nums[pref[n - 1]];
        for(int i = n - 2; i >= 0; i--) {
            ans[i] = nums[pref[i]];
            if(nums[pref[i]] > nums[suff[i + 1]]) ans[i] = max(ans[i], ans[i + 1]);
        }
        return ans;
    }
};