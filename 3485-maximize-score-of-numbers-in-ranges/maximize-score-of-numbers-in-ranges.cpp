class Solution {
public:
    bool fun(int mid, vector<int>& start, int d) {
        long long a = start[0];
        for(int i = 1; i < start.size(); i++) {
            long long b = max(a + mid, 1LL * start[i]);
            if(b >= start[i] && b <= start[i] + d) {
                a = b;
            } else return false;
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(), start.end());
        int lo = 0;
        int hi = start.back() + d;
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(fun(mid, start, d)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};