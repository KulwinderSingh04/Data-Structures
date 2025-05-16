class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while(i < j) {
            while(i < j && nums[i] % 2 == 0) i++;
            while(i < j && nums[j] % 2 == 1) j--;
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        return nums;
    }
};