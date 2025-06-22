class Solution {
public:
    int fun(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(idx == n)  {
            return sum == 0;
        }  
        if(dp[idx][sum] != -1) return dp[idx][sum];
        long long a = 0;
        if(sum - nums[idx] >= 0) a = fun(idx, sum - nums[idx], nums, dp);
        long long b = fun(idx + 1,  sum, nums, dp);
        return dp[idx][sum] = a + b;
    }
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> ans;
        // cout << n;
        for(int i = 0; i < n; i++) {
            // cout << numWays[i] << " ";
            // if(numWays[i] == 0) continue;
            vector<vector<int>> dp(n, vector<int> (n + 1, -1));
            int t = fun(0, i + 1, ans, dp);
            // for(auto x : ans) cout << x << " ";
            // cout << endl;
            // cout << t << " ";
            if(t == numWays[i] - 1) ans.push_back(i + 1);
            else if(t != numWays[i]) return {};
        }
        return ans;
    }
};