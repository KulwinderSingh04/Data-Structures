class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> bit(32);
        vector<int> ans(n, 1);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < 32; j++) {
                if((nums[i] & (1 << j))) {
                    bit[j] = i;
                }
            }
            for(int j = 0; j < 32; j++) {
                ans[i] = max(ans[i], bit[j] - i + 1);
            }
        }
        return ans;
    }
};