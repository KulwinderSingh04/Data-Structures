class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[nums[i]] <= 1000) nums[i] = nums[i] + 10000 * nums[nums[i]];
            else {
                int n2 = nums[nums[i]] % 10000;
                nums[i] = nums[i] + 10000 * n2;
            }
        }
        for(int i = 0;i < nums.size(); i++) nums[i] /= 10000;
        return nums;
    }
};