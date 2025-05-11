class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& nums) {
        int n = nums.size();
        for(int i = 2; i < n; i++) {
            if(nums[i] % 2 == 1 && nums[i - 1] % 2 == 1 && nums[i - 2] % 2 == 1) return true;
        }
        return false;
    }
};