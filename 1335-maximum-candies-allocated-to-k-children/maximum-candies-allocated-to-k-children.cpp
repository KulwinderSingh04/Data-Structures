class Solution {
public:
    bool fun(long long mid, vector<int>& candies, long long k) {
        long long ans = 0;
        int n = candies.size();
        for(int i = 0; i < n; i++) {
            ans += candies[i] / mid;
        }
        return ans >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int mx = INT_MIN;
        int n = candies.size();
        for(int i = 0; i < n; i++) {
            mx = max(candies[i], mx);
        }
        int lo = 0;
        int hi = mx;
        int ans = 0;
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(mid == 0 || fun(mid, candies, k)) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};