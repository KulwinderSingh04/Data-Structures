class Solution {
public:
    bool fun(int mid, int mxSum, long idx, int n) {
        // vector<int> v(n);
        // v[idx] = mid;
        // cout << mid << " ";
        long long sum = (1LL * mid * (mid + 1)) / 2;
        // cout << sum << " ";
        if(idx >= mid) sum += ((idx - mid + 1));
        else {
            long long t = mid - idx - 1;
            sum -= t * (t + 1) / 2;
        }
        // cout << sum << " ";
        sum += (1LL * mid * (mid - 1)) / 2;
        if(n - 1 - (idx) >= mid - 1) sum += (n - 1 - (idx)) - (mid - 1);
        else {
            long long t = mid - 1 - (n - 1 - (idx));
            sum -= (t * (t + 1)) / 2;
        }
        // cout << sum << " ";
        return sum <= mxSum;

    }
    int maxValue(int n, int index, int maxSum) {
        int lo = 1;
        int hi = maxSum;
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(fun(mid, maxSum, index, n)) {
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;
    }
};