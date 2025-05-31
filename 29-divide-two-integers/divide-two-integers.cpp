class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend / (divisor * 1LL);
        if(a > INT_MAX) return INT_MAX;
        if(a < INT_MIN) return INT_MIN;
        return a;
    }
};