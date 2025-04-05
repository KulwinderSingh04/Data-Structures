class Solution {
public:
    void fun(vector<int>& nums, int i, int& xo, int& ans) {
        int n = nums.size();
        if(i == n) return;
        int x = xo;
        xo ^= nums[i];
        ans += xo;
        fun(nums, i + 1, xo, ans);
        xo = x;
        fun(nums, i + 1, xo, ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, xo = 0;
        fun(nums, 0, xo, ans);
        return ans;
    }
};