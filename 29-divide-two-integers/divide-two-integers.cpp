class Solution {
public:
    int divide(int n, int d) {
        long long ans = 0;
        int sign = 1;
        if(n < 0 && d >= 0) sign = -1;
        if(n >= 0 && d < 0) sign = -1;
        cout << sign << endl;
        long long n1 = n;
        long long d1 = d;
        n1 = abs(n1);
        d1 = abs(d1);
        while(n1 >= d1) {
            long long cnt = 0;
            while(n1 >= (1LL * (d1 << (cnt + 1)))) cnt++;
            ans += (1 << cnt);
            n1 -= (d1 << cnt);
        }
        if(ans == (1 << 31) && sign == 1) return INT_MAX;
        if(ans == (1 << 31) && sign == -1) return INT_MIN;
        if(sign == -1) ans *= -1;
        return ans;
    }
};