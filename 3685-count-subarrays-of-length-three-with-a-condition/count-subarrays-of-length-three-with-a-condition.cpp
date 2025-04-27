class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int count = 0, sum = 0;
        while(i < n) {
            sum += nums[i];
            if(i >= 2) {
                if(2 * (nums[i] + nums[i - 2]) == nums[i - 1]) count++;
                sum -= nums[i - 2];
            }
            i++;
        }
        return count;
    }
};