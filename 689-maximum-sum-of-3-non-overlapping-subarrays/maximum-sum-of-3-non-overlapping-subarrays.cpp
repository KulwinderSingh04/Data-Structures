class Solution {
public:
    vector<vector<int>> dp;
    int fun(int i, int count, vector<int>& v, int k) {
        int n = v.size();
        if(i >= n) {
            if(count == 0) return 0;
            return INT_MIN;
        }
        if(count < 0) return INT_MIN;
        if(dp[i][count] != -1) return dp[i][count];
        int pick = v[i] + fun(i + k, count - 1, v, k);
        int np = fun(i + 1, count, v, k);
        return dp[i][count] = max(pick, np);
    }

    void solve(int i, int count, int k, vector<int>& nums, vector<int>& res) {
        int n = nums.size();
        if(i >= n) return;

        int a = nums[i] + fun(i + k, count - 1, nums, k);
        int b = fun(i + 1, count, nums, k);
        if(a >= b) {
            res.push_back(i);
            solve(i + k, count - 1, k, nums, res);
        } else {
            solve(i + 1, count, k, nums, res);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        vector<int> v(n);
        for(int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            if(i < n - k) sum -= nums[i + k];
            v[i] = sum;
        }
        for(int i = 0; i < k - 1; i++) v.pop_back();
        dp.resize(v.size(), vector<int> (4, -1));
        vector<int> res;
        solve(0, 3, k, v, res);
        return res;
    }
};