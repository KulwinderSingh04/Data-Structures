class Solution {
public:
    long long fun(long long mid, vector<int>& coins) {
        int n = coins.size();
        long long cnt = 0;
        for(int i = 1; i < (1 << n); i++) {
            long long l = 1;
            int c = 0;
            for(int bit = 0; bit < 32; bit++) {
                if((i & (1 << bit))) {
                    c++;
                    l = lcm(l, coins[bit]);
                }
            }

            if(c % 2) cnt += mid / l;
            else cnt -= mid / l;
        }
        return cnt;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long lo = 0;
        long long hi = 1e11;
        long long ans = 0;
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(fun(mid, coins) >= k) {
                ans = mid;
                hi = mid - 1;
            } 
            else lo = mid + 1;
        }
        return ans;
    }
};