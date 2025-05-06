class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if(nums[nums[i]] < n) nums[i] = nums[i] + n * nums[nums[i]];
            else {
                int n2 = nums[nums[i]] % n;
                nums[i] = nums[i] + n * n2;
            }
        }
        for(int i = 0;i < nums.size(); i++) nums[i] /= n;
        return nums;
    }
};