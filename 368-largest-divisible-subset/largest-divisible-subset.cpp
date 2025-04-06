class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> par(n);
        int idx = 0;
        for(int i = 0; i < n; i++) par[i] = i;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = dp[j] + 1;
                        par[i] = j;
                    }
                }
            }
            if(dp[idx] < dp[i]) {
                idx = i;
            }
        }
        int i = idx;
        vector<int> ans;
        while(i != par[i]) {
            ans.push_back(nums[i]);
            i = par[i];
        }
        ans.push_back(nums[i]);
        reverse(ans.begin(), ans.end());
        return ans;

    }
};