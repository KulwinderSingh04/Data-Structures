class Solution {
public:
    int fun(int n, int& a, int& b) {
        if(n == 0) return 1;
        int t = n;
        while(t % 5 == 0) {
            a++;
            t /= 5;
        }
        while(t % 2 == 0) {
            b++;
            t /= 2;
        }
        return fun(n - 1, a, b);
    }
    int trailingZeroes(int n) {
        int a = 0, b = 0;
        fun(n, a, b);
        return min(a, b);
    }
};