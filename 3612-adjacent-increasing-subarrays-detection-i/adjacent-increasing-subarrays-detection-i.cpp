class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1;
        int a = 0;
        if(k == 1) return true;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) count++;
            else {
                if(count >= 2 * k) return true;
                if(count >= k) {
                    a++;
                    count = 1;
                    if(a == 2) return true;
                } else {
                    count = 1;
                    a = 0;
                }
            }
        }
        if(count >= 2 * k) return true;
        if(count >= k) {
            a++;
            count = 1;
            if(a == 2) return true;
        } else {
            count = 1;
            a = 0;
        }
        return false;
    }
};