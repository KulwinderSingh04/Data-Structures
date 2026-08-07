class Solution {
public:
    bool fun(int n, int t) {
        int pr = 1;
        while(n) {
            int rem = n % 10;
            pr *= rem;
            n /= 10;
        }
        return pr % t == 0;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i < n + 11; i++) {
            if(fun(i, t)) return i;
        }
        return 0;
    }
};