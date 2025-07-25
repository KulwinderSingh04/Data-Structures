class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.back() < 0) return nums.back();
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) continue;

            if(i - 1 >= 0 && nums[i] == nums[i - 1]) continue;
            sum += nums[i];
        }
        return sum;
    }
};