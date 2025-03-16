class Solution {
public:
    bool fun(vector<int>& ranks, int cars, long long mid) {
        int n = ranks.size();
        long long c = 0;
        for(int i = 0; i < n; i++) {
            c += (int)sqrt(mid / ranks[i]);
        }
        return c >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long lo = 0;
        int mx = 0;
        int n = ranks.size();
        for(int i = 0; i < n; i++) mx = max(mx, ranks[i]);
        long long hi = 1LL * mx * cars * cars;
        long long ans = 0;
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(fun(ranks, cars, mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};