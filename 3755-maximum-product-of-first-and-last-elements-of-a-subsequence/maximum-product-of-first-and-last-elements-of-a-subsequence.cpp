class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans = LLONG_MIN;
        int n = nums.size();
        vector<long long> posPre(n, nums[0]), negPre(n, nums[0]);
        // if(nums[0] > 0) posPre[0] = nums[0];/
        for(int i = 1; i < nums.size(); i++) {
            posPre[i] = max(posPre[i - 1], 1LL * nums[i]);
        }
        if(nums[0] < 0) posPre[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            negPre[i] = min(negPre[i - 1], 1LL * nums[i]);
        }
        for(int j = 0; j < n; j++) {
            if(j >= m - 1) {
                int idx = j - m + 1;
                ans = max(ans, 1LL * posPre[idx] * nums[j]);
                ans = max(ans, 1LL * negPre[idx] * nums[j]);
            }
        }
        return ans;
    }
};