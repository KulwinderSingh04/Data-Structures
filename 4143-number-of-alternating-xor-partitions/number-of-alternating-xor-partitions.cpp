class Solution {
public:
    int MOD = 1e9 + 7;
    long long fun(int i, int x, int toggle, vector<int>& nums, vector<int>& v, unordered_map<long long, int>& dp) {
        int n = nums.size();
        x ^= nums[i];
        if(i == n - 1) return x == v[toggle];
        long long stateKey =((long long)i << 32) |((long long)x << 1) | toggle;
        if(dp.find(stateKey) != dp.end()) return dp[stateKey];
        long long a = 0;
        if(x == v[toggle]) {
            a = fun(i + 1, 0, !toggle, nums, v, dp);
        }
        long long b = fun(i + 1, x, toggle, nums, v, dp);
        return dp[stateKey] = (a + b) % MOD;
    }
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        vector<int> v = {target1, target2};
        // int n = nums.size();
        // for(int i = 1; i < n; i++) {
        //     nums[i] = nums[i - 1] ^ nums[i];
        // }
        unordered_map<long long, int> dp;
        return fun(0, 0, 0, nums, v, dp);
        
    }
};