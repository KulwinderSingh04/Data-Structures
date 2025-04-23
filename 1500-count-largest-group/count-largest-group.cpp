class Solution {
public:
    int sumDigits(int x) {
        int a = 0;
        while(x) {
            a += x % 10;
            x /= 10;
        }
        return a;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        int mx = 0;
        for(int i = 1; i < n + 1; i++) {
            int t = sumDigits(i);
            m[t]++;
            mx = max(mx, m[t]);
        }
        int ans = 0;
        for(auto x : m) {
            if(x.second == mx) ans++;
        }
        return ans;
    }
};