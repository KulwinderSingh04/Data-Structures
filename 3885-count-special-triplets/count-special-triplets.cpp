class Solution {
public:
    int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, long long> mp1, mp2;
        for(auto x : nums) mp2[x]++;
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp2[nums[i]]--;
            ans += mp1[2 * nums[i]] * mp2[2 * nums[i]];
            ans %= MOD;
            mp1[nums[i]]++;
        }
        return ans;
    }
};