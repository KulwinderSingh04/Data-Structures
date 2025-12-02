class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int mx = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mx = max(mx, abs(sum));
            if(sum < 0) sum = 0;
        }
        return mx;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> v = nums;
        for(auto& x : v) x *= -1;
        return max(maxSubarray(v), maxSubarray(nums));
    }
};