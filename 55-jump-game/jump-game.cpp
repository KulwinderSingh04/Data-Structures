class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i < n - 1) {
            int a = 0;
            int idx = 0;
            if(nums[i] == 0) return false;
            for(int j = i + 1; j < min(n, i + nums[i] + 1); j++) {
                if(j + nums[j] > a) {
                    a = j + nums[j];
                    idx = j; 
                }
            }
            i = idx;
        }
        return true;
    }
};