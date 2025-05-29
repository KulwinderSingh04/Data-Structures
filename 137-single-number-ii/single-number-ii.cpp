class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 1;
        while(i < n) {
            if(nums[i] != nums[i - 1]) return nums[i - 1];
            i += 3;
        }
        return nums.back();
    }
};