class Solution {
public:
    void fun1(int i, int sum, vector<int>& nums, vector<int>& v) {
        int n = nums.size();
        if(i == n) {
            v.push_back(sum);
            return;
        }
        fun1(i + 1, sum + nums[i], nums, v);
        fun1(i + 1, sum, nums, v);
    }
    void fun2(int i, int sum, vector<int>& nums, vector<int>& v, int& ans) {
        int n = nums.size();
        if(i == n) {
            int idx = lower_bound(v.begin(), v.end(), sum) - v.begin();
            if(idx < v.size()) ans = min(ans, abs(sum - v[idx]));
            if(idx - 1 >= 0) ans = min(ans, abs(sum - v[idx - 1]));
            return;
        }
        fun2(i + 1, sum - nums[i], nums, v, ans);
        fun2(i + 1, sum, nums, v, ans);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> v, nums1, nums2;
        for(int i = 0; i < n; i++) {
            if(i < n / 2) nums1.push_back(nums[i]);
            else nums2.push_back(nums[i]);
        }
        fun1(0, 0, nums1, v);
        sort(v.begin(), v.end());
        int ans = 1e9;
        fun2(0, goal, nums2, v, ans);
        return ans;
    }
};