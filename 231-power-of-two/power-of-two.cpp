class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long a = n;
        if(a == 0) return false;
        return (a & a - 1) == 0;
    }
};