class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        // vector<int> ans(n);
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                nums[i] += nums[i + 1];
                nums[i + 1] = 0;
            }
        }
        int i = 0;
        int j = 0;
        while(j < n) {
            if(nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        while(i < n) {
            nums[i] = 0;
            i++;
        }
        return nums;
    }
};