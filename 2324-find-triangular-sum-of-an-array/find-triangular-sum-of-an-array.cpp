class Solution {
public:
    int ncr(int n, int r) {
        if (r > n) return 0;
        int n2 = n, r2 = r;
        int mod2 = 1;
        while (n2 > 0 || r2 > 0) {
            int nd = n2 & 1, rd = r2 & 1;
            if (rd > nd) { mod2 = 0; break; }
            n2 >>= 1; r2 >>= 1;
        }
        int n5 = n, r5 = r;
        int mod5 = 1;
        while (n5 > 0 || r5 > 0) {
            int nd = n5 % 5, rd = r5 % 5;
            if (rd > nd) { 
                mod5 = 0; 
                break; 
            }
            int val = 1;
            for (int i = 1; i <= rd; i++) {
                val = val * (nd - i + 1) / i;
            }
            mod5 = (mod5 * (val % 5)) % 5;

            n5 /= 5; r5 /= 5;
        }
        for (int x = 0; x < 10; x++) {
            if (x % 2 == mod2 && x % 5 == mod5) return x;
        }
        return 0;
    }

    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            cout << ncr(n - 1, i) << " ";
            ans += 1LL * ncr(n - 1, i) * nums[i];
            ans %= 10;
        }
        return ans;
    }
};