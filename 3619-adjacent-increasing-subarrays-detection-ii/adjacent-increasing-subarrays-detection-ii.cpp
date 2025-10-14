class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1), suff(n, 1);
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            pref[i] = count;
        }
        count = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                count++;
            } else {
                count = 1;
            }
            suff[i] = count;
        }
        int ans = 1;
        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, min(pref[i], suff[i + 1]));
        }
        return ans;
    }
};