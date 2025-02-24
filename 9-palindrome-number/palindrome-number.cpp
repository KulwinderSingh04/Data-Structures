class Solution {
public:
    bool isPalindrome(int x) {
        int num = 0;
        if(x < 0) return false;
        int n = x;
        long long m = 0;
        while(n) {
            int r = n % 10;
            m = m * 10 + r;
            n /= 10;
        }
        return m == x;
    }
};