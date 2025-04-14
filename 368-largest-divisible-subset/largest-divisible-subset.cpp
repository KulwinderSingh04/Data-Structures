class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> hash(n);
        for(int i = 0; i < n; i++) hash[i] = i;
        vector<int> dp(n, 1);
        int idx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = dp[j] + 1;
                        hash[i] = j;
                    }
                }
            }
            if(dp[idx] < dp[i]) {
                idx = i;
            }
        }
        vector<int> ans;
        while(idx != hash[idx]) {
            ans.push_back(nums[idx]);
            idx = hash[idx];
        }
        ans.push_back(nums[idx]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};