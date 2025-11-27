class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        vector<long long> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = nums[i] + pref[i - 1];
        }
        for(int i = 0; i < k; i++) {
            int l = i;
            int r = i + k - 1;
            long long sum = 0;
            while(r < n) {
                long long v = (l == 0 ? pref[r] : pref[r] - pref[l - 1]);
                // cout << v << " ";
                sum += v;
                ans = max(ans, sum);
                if(sum < 0) {
                    sum = 0;
                }
                l += k;
                r += k;
            }
        }
        return ans;
    }
};