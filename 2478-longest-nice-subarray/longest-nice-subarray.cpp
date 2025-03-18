class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int i = 0;
        int j = 0;
        int mask = 0;
        while(j < n) {
            if((mask & nums[j]) != 0) {
                i++;
                mask ^= nums[i - 1];
            }
            else {
                ans = max(ans, j - i + 1);
                mask |= nums[j];
                j++;
            }
            
        }
        return ans;
    }
};