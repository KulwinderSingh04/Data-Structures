class Solution {
public:
    bool fun(long long mid, vector<int>& stations, int r, int k) {
        long long b = -r;
        long long f = r;
        long long n = stations.size();
        long long sum = 0;
        for(long long i = 0; i < r; i++) sum += stations[i];
        vector<long long> nums(n);
        for(int j = 0; j < n; j++) {
            if(f < n) sum += (1LL * stations[f] + nums[f]);
            if(sum < mid) {
                if(k >= mid - sum) {
                    nums[min(f, n - 1)] += (mid - sum);
                    k -= (mid - sum);
                    sum += (mid - sum);
                } else {
                    return false;
                }
            }
            // if(mid == 5) cout << k << " ";
            f++;
            if(b >= 0) sum -= (1LL * stations[b] + nums[b]);
            // if(mid == 5) cout << sum << " ";
            b++;
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long long lo = 0;
        long long hi = k + accumulate(stations.begin(), stations.end(), 0LL);
        long long ans = 0;
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(fun(mid, stations, r, k)) {
                // cout << mid << " ";
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};