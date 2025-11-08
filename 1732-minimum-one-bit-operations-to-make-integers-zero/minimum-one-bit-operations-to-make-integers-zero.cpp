class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long> memo(32);
        memo[0] = 1;
        for(int i = 1; i < 32; i++) {
            memo[i] = 1LL * 2 * memo[i - 1] + 1;
        }
        int ans = 0, count = 0;
        for(int i = 31; i >= 0; i--) {
            if(n & (1 << i)) {
                if(count % 2) ans -= memo[i];
                else ans += memo[i];
                count++;
            }
        }
        return ans;
    }
};