class Solution {
public:
    int fun(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n);
        int t = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            t = max(t, sum);
            right[i] = t;
        }
        int mx2 = INT_MIN;
        int s = 0;
        for(int i = n - 1; i > 0; i--) {
            s += nums[i];
            mx2 = max(mx2, s + right[i - 1]);
        }
        return mx2;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mx1 = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mx1 = max(mx1, sum);
            if(sum < 0) sum = 0;
        }
        vector<int> v = nums;
        reverse(v.begin(), v.end());
        return max({mx1, fun(nums), fun(v)});
    }
};