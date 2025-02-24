class Solution {
public:
    int reverse(int x) {
        long long n = x;
        long long m = 0;
        while(n) {
            int r = n % 10;
            m = m * 10 + r;
            n /= 10;
        }
        if(m < INT_MIN || m > INT_MAX) return 0;
        return m;
    }
};