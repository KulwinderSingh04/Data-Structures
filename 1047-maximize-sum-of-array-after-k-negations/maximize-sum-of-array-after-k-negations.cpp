class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        int mnIdx = 0;
        for(int i = 0; i < n; i++) {
            if(k && nums[i] < 0) {
                k--;
                nums[i] *= -1;
            } else if(k && nums[i] == 0) {
                k = 0;
            } else if(k && nums[i] > 0) {
                if(abs(nums[mnIdx]) > abs(nums[i])) mnIdx = i;
                break;
            }
            if(abs(nums[mnIdx]) > abs(nums[i])) mnIdx = i;
        }
        if(k % 2 == 1) nums[mnIdx] *= -1;
        for(int i = 0; i < n; i++) {
            ans += nums[i];
        }
        return ans;
    }
};