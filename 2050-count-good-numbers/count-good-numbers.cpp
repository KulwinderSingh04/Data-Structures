class Solution {
public:
    long long pow(long long a, long long b) {
        if(b == 0) return 1;
        long long x = pow(a, b / 2);
        if(b % 2 == 0) return (x * x) % 1000000007;
        return (x * x * a) % 1000000007;
    }
    int countGoodNumbers(long long n) {
        if(n % 2 == 0) return (pow(4, n / 2) * pow(5, n / 2)) % 1000000007;
        return (pow(4, n / 2) * pow(5, n / 2 + 1)) % 1000000007;
    }
};