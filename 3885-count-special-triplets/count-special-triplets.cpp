class Solution {
public:
    int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<long long, long long> leftMap, rightMap;
        for(auto x : nums) rightMap[x]++;
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            rightMap[nums[i]]--;
            ans += leftMap[1LL * 2 * nums[i]] * rightMap[2 * nums[i]];
            leftMap[nums[i]]++;
            ans %= MOD;
        }
        return ans;
    }
};