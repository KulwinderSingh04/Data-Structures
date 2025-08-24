class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        while(j < n) {
            if(nums[j] == 0) count++;
            while(count > 1) {
                if(nums[i] == 0) count--;
                i++;
            }
            ans = max(ans, j - i);
            j++;
        }
        return ans;
    }
};