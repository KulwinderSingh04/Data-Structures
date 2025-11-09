class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        int ans = 0;
        int c1 = 1, c2 = 1;
        bool flag = true;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] <= nums[i]) {
                left[i] = 1 + left[i - 1];
            }
            c1 = max(c1, left[i]);
        }
        if(c1 != n) c1++;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] <= nums[i + 1]) {
                right[i] = 1 + right[i + 1];
            } 
            c2 = max(c2, right[i]);
        }
        if(c2 != n) c2++;
        for(int i = 1; i < n - 1; i++) {
            if(nums[i - 1] <= nums[i + 1]) ans = max(ans, left[i - 1] + 1 + right[i + 1]);
        }
        return max({ans, c1, c2});
    }
};