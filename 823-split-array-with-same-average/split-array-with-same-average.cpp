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
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums1, nums2;
        for(int i = 0; i < n; i++) {
            if(i < n / 2) nums1.push_back(nums[i]);
            else nums2.push_back(nums[i]);
        }
        vector<vector<int>> v1(n / 2 + 1), v2(n - n / 2 + 1);
        fun(0, 0, 0, nums1, v1);
        fun(0, 0, 0, nums2, v2);
        for(auto& x : v2) {
            sort(x.begin(), x.end());
        }
        int tot = accumulate(nums.begin(), nums.end(), 0);
        for(int k = 0; k <= n / 2; k++) {
            for(auto leftSubSum : v1[k]) {
                for(int m = 0; m <= n / 2; m++) {
                    int sz = k + m;
                    if(sz == 0 || sz == n) continue;
                    if(tot * sz % n) continue;
                    int rightSubSum = tot * sz / n - leftSubSum;
                    auto itr = lower_bound(v2[m].begin(), v2[m].end(), rightSubSum);
                    if(itr == v2[m].end() || *itr != rightSubSum) continue;
                    return true;
                }
            }
        }
        return false;
    }
};