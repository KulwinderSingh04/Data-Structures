class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x = 0;
        for(auto e : nums) {
            x ^= e;
        }
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int k = 0;
            for(int bit = 0; bit < maximumBit; bit++) {
                if((x & (1 << bit)) == 0) {
                    k |= (1 << bit);
                }
            }
            ans.push_back(k);
            x ^= nums[n - 1 - i];
        }
        return ans;
    }
};