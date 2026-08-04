class Solution {
public:
    void fun(int i, int sum, int k, vector<int>& nums, vector<vector<int>>& v) {
        int n = nums.size();
        if(i == n) {
            v[k].push_back(sum);
            return;
        }
        fun(i + 1, sum + nums[i], k + 1, nums, v);
        fun(i + 1, sum, k, nums, v);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums1, nums2;
        int tot = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < n; i++) {
            if(i < n / 2) nums1.push_back(nums[i]);
            else nums2.push_back(nums[i]);
        }
        vector<vector<int>> v1(n / 2 + 1), v2(n / 2 + 1);
        fun(0, 0, 0, nums1, v1);
        fun(0, 0, 0, nums2, v2);
        for(auto& x : v1) {
            sort(x.begin(), x.end());
        }
        for(auto& x : v2) {
            sort(x.begin(), x.end());
        }
        int ans = 1e9;
        for(int i = 0; i < n / 2 + 1; i++) {
            for(auto x : v1[i]) {
                int leftSum = x;
                int rightSum = (tot - 2 * leftSum) / 2;
                int idx = lower_bound(v2[n / 2 - i].begin(), v2[n / 2 - i].end(), rightSum) - v2[n / 2 - i].begin();
                if(idx < v2[n / 2 - i].size()) ans = min(ans, abs(tot - 2 * (leftSum + v2[n / 2 - i][idx])));
                if(idx - 1 >= 0) ans = min(ans, abs(tot - 2 * (leftSum + v2[n / 2 - i][idx - 1])));
            }
        }
        return ans;
    }
};