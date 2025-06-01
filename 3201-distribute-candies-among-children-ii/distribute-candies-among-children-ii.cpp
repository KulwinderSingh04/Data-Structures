class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        int mn = max(0, n - 2 * limit);
        int mx = min(n, limit);
        for(int i = mn; i <= mx; i++) {
            int nn = n - i;
            int mn2 = max(0, nn - limit);
            int mx2 = min(nn, limit);
            if(mx2 - mn2 + 1 > 0) ans += mx2 - mn2 + 1;
        }
        return ans;
    }
};