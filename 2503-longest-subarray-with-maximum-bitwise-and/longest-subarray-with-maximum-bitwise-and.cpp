class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > mx) mx = nums[i];
        }
        int ans = 0, count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == mx) count++;
            else {
                ans = max(ans, count);
                count = 0;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};