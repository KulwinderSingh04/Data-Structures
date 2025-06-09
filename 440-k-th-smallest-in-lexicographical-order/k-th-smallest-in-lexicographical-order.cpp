class Solution {
public:
    int count(long long curr, long long next, int n) {
        int c = 0;
        while(curr <= n) {
            c += (next - curr);
            next *= 10;
            curr *= 10;
            next = min(1LL * n + 1, next);
        }
        return c;
    }
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;
        while(k > 0) {
            int c = count(curr, curr + 1, n);
            if(c <= k) {
                k -= c;
                curr++;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};