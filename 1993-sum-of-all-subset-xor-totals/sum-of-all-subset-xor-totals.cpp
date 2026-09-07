class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int o = 0;
        int n = nums.size();
        int ans = 0;
        for(auto x : nums) o |= x;
        for(int i = 0; i < 32; i++) {
            if(o & (1 << i)) {
                ans += (1 << (n - 1)) * (1 << i);
            }
        }
        return ans;
    }
};