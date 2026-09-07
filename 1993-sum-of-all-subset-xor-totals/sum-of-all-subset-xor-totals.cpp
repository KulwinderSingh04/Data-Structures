class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int o = 0;
        int n = nums.size();
        int ans = 0;
        for(auto x : nums) o |= x;
        return o * (1 << (n - 1));
    }
};