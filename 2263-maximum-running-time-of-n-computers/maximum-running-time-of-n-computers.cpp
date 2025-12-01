class Solution {
public:
    bool fun(long long mid, vector<int>& batteries, int n) {
        long long sum = 0;
        long long target = 1LL * n * mid;
        for(int i = 0; i < batteries.size(); i++) {
            sum += min(mid, 1LL * batteries[i]);
            if(sum >= target) {
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        if(batteries.size() < n) return 0;
        sort(batteries.begin(), batteries.end(), greater<int> ());
        long long lo = 0;
        long long sum = 0;
        for(auto x : batteries) sum += x;
        long long hi = sum;
        long long ans = 0;
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(fun(mid, batteries, n)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};