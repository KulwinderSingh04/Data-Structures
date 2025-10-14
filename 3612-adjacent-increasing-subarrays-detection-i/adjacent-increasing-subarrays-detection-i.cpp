class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1;
        if(k == 1) return true;
        for(int i = 0; i <= n - 2 * k; i++) {
            int j1 = i + 1;
            int j2 = i + k + 1;
            bool flag = true;
            while(j2 < i + 2 * k) {
                if(nums[j1] <= nums[j1 - 1] || nums[j2] <= nums[j2 - 1]) {
                    flag = false;
                    break;
                }
                j1++;
                j2++;
            }
            if(flag) return true;
        }
        return false;
    }
};