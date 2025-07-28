class Solution {
public:
    int fun(int i, int bitOr, int& mx, vector<int>& nums, unordered_map<string, int>& dp) {
        int n = nums.size();
        if(i == n) return bitOr == mx;
        string str = to_string(i) + '_' + to_string(bitOr);
        if(dp.find(str) != dp.end()) return dp[str];
        int p = fun(i + 1, bitOr | nums[i], mx,  nums, dp);
        int np = fun(i + 1, bitOr, mx, nums, dp);
        return dp[str] = np + p; 
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int mx = 0;
        for(auto x : nums) mx |= x;
        unordered_map<string, int> dp;
        return fun(0, 0, mx, nums, dp);
    }
};