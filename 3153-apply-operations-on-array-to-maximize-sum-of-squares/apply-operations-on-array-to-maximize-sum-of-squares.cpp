class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> vec(32);
        int n = nums.size();
        for(auto x : nums) {
            for(int bit = 0; bit < 32; bit++) {
                if(x & (1 << bit)) {
                    vec[bit]++;
                }
            }
        }
        int MOD = 1e9 + 7;
        long long ans = 0;
        for(int i = 0; i < k; i++) {
            long long num = 0;
            for(int bit = 0; bit < 32; bit++) {
                if(vec[bit]) {
                    num |= (1 << bit);
                    vec[bit]--;
                }
            }
            ans += num * num;
            ans %= MOD;
        }
        return ans;
    }
};