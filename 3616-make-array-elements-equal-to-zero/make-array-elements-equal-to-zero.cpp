class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        for(auto x : nums) right += x;
        int count = 0;
        for(int i = 0; i < n; i++) {
            left += nums[i];
            right -= nums[i];
            if(nums[i] == 0) {
                if(left - right >= 0 && left - right <= 1) count++;
                if(right - left >= 0 && right - left <= 1) count++;
            }
        }
        return count;
    }
};