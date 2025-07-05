class Solution {
public:
    void fun(int i, int sum, vector<int>& ans, vector<int>& nums, int e) {
        int n = nums.size();
        if(i == e) {
            ans.push_back(sum);
            return;
        }
        fun(i + 1, sum + nums[i], ans, nums, e);
        fun(i + 1, sum, ans, nums, e);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> v1, v2;
        fun(0, 0, v1, nums, n / 2);
        fun(n / 2, 0, v2, nums, n);
        sort(v2.begin(), v2.end());
        int ans = INT_MAX;
        for(int i = 0; i < v1.size(); i++) {
            auto l = lower_bound(v2.begin(), v2.end(), goal - v1[i]);
            int idx = l - v2.begin();
            if(idx < v2.size()) ans = min(ans, abs(v2[idx] + v1[i] - goal));
            if(idx - 1 >= 0) ans = min(ans, abs(v2[idx - 1] + v1[i] - goal));
        }
        return ans;
    }
};