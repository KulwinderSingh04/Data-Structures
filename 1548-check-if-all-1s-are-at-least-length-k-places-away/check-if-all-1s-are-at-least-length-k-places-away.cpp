class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = 0;
        int prev = -1e8;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                if(i - prev <= k) return false;
                prev = i;
            }
        }
        return true;
    }
};