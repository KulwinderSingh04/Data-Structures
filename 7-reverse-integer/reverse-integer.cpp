class Solution {
public:
    int reverse(int x) {
        int val = 1;
        long long n = x;
        if(n < 0) {
            val = -1;
            n *= -1;
        }
        long long m = 0;
        while(n) {
            int r = n % 10;
            m = m * 10 + r;
            n /= 10;
        }
        m *= val;
        if(m < INT_MIN || m > INT_MAX) return 0;
        return m;
    }
};