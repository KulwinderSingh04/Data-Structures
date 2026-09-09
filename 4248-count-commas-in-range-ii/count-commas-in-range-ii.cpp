class Solution {
public:
    long long countCommas(long long n) {
        long long num = 1;
        long long ans = 0;
        int cnt = 0;
        while(num * 10 <= n) {
            num *= 10;
            cnt++;
            long long c = num - num / 10;
            // cout << c << " " << cnt << " " << num << endl;
            ans += c * ((cnt - 1) / 3);
        }
        cnt++;
        // cout << num << " " << cnt << endl;
        ans += (n - num + 1) * ((cnt - 1) / 3);
        return ans;

    }
};