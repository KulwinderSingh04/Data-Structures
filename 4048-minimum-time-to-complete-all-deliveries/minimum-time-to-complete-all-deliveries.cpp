class Solution {
public:
    bool fun(long long mid, vector<int>& d, vector<int>& r) {
        bool a = d[1] <= (mid - mid / r[1]);
        bool b = d[0] <= (mid - mid / r[0]);
        bool c = (d[0] + d[1]) <= (mid - mid / lcm(r[0], r[1]));
        return a && b && c;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long lo = 0;
        long long hi = 1e12;
        long long ans = 0;
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(fun(mid, d, r)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;

    }
};