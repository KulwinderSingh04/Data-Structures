class Solution {
public:
    void fun(int i, int sum, int k, vector<vector<int>>& ans, vector<int>& nums, int e) {
        int n = nums.size();
        if(i == e) {
            ans[k].push_back(sum);
            return;
        }
        fun(i + 1, sum + nums[i], k + 1, ans, nums, e);
        fun(i + 1, sum, k, ans, nums, e);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(auto x : nums) totSum += x;
        vector<vector<int>> v1(n / 2 + 1), v2(n / 2 + 1);
        fun(0, 0, 0, v1, nums, n / 2);
        fun(n / 2, 0, 0, v2, nums, n);
        for(int i = 0; i < v2.size(); i++) {
            sort(v2[i].begin(), v2[i].end());
        }
        int ans = INT_MAX;
        for(int k = 1; k < v1.size(); k++) {
            for(int i = 0; i < v1[k].size(); i++) {
                auto l = lower_bound(v2[n / 2 - k].begin(), v2[n / 2 - k].end(),(totSum - 2 * v1[k][i]) / 2); 
                int idx = l - v2[n / 2 - k].begin();
                if(idx < v2[n / 2 - k].size()) ans = min(ans, abs(totSum - 2 * (v1[k][i] + v2[n / 2 - k][idx])));
                if(idx - 1 >= 0) ans = min(ans, abs(totSum - 2 * (v1[k][i] + v2[n / 2 - k][idx - 1])));
            }
        }
        return ans;
    }
};