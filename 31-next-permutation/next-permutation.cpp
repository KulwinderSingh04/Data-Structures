class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pvt = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pvt = i;
                break;
            }
        }
        if(pvt == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        reverse(nums.begin() + pvt + 1, nums.end());
        int idx = pvt;
        for(int i = pvt + 1; i < n; i++) {
            if(nums[i] > nums[pvt]) {
                idx = i;
                break;
            }
        }
        swap(nums[idx], nums[pvt]);
    }
};