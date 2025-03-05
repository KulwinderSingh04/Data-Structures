class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1) return 1;
        long long ans = 1 + (1LL * 4 * (1LL * n * (n - 1) / 2));
        return ans;
    }
};