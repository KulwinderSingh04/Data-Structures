class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);
        int sz = s.size();
        long long num = 1;
        while(num * 10 <= n) num *= 10;
        // cout << num << endl;
        long long ans = (n - num + 1) * ((sz % 3 == 0) ? sz / 3 - 1: sz / 3);
        // cout << ans << endl;
        long long t = 9000;
        for(int i = 4; i < sz; i++) {
            ans += t * ((i % 3 == 0) ? i / 3 - 1: i / 3);
            t *= 10;
        }
        return ans;
    }
};