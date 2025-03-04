class Solution {
public:
    bool checkPowersOfThree(int n) {
        int t = n;
        int hi = 16;
        int lo = 0;
        while(t > 0) {
            int x = -1;
            while(lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if(pow(3, mid) <= t) {
                    x = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            if(x == -1) break;
            t -= pow(3, x);
            hi = x - 1;
            lo = 0;
        }
        cout << t << endl;
        return t == 0;
    }
};