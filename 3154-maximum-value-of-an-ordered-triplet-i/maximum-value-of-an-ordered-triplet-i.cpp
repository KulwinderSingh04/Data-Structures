class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long imax = 0;
        long long dmax = 0;
        for(int k = 0; k < n; k++) {
            ans = max(ans, 1LL * dmax * nums[k]);
            dmax = max(dmax, 1LL * imax - nums[k]);
            imax = max(imax, 1LL * nums[k]);
        }
        return ans;
    }
};