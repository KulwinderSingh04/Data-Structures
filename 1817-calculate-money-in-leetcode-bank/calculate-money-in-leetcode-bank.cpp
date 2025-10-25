class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        ans += n / 7 * 28;
        int terms = n / 7;
        ans += terms * (terms - 1) * 7 / 2;
        // cout << ans << " ";
        if(n % 7 == 0) return ans;
        // n %= 7;
        int starting = n / 7 + 1;
        ans += n % 7 * (2 * starting + (n % 7 - 1)) / 2;
        return ans;
    }
};