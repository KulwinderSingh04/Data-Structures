class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < nums.size() - 1 - j; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            // nums.pop_back();
        }
        return nums[0];
    }
};