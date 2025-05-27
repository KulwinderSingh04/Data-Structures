class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long num1 = n * (n + 1) / 2, sum;
        sum = num1;
        long long num2 = 0;
        int a = m;
        while(a <= n) {
            num2 += a;
            num1 -= a;
            a += m;
        }
        return num1 - num2;
    }
};