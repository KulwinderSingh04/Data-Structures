class Solution {
public:
    string concatHex36(int n) {
        long long x = n * n;
        string a1 = "";
        while(x) {
            int rem = x % 16;
            if(rem < 10) a1 += rem + 48;
            else a1 += rem + 55;
            x /= 16;
        }

        long long y = 1LL * n * n * n;
        string a2 = "";
        while(y) {
            int rem = y % 36;
            if(rem < 10) a2 += rem + 48;
            else a2 += rem + 55;
            y /= 36;
        }
        reverse(a1.begin(), a1.end());
        reverse(a2.begin(), a2.end());
        return a1 + a2;
    }
};