class Solution {
public:
    int isdivisible7(string num)
    {
        int n = num.length(), gSum=0;
        if (n == 0)
            return 1;

        // Append required 0s at the beginning.
        if (n % 3 == 1) {
            num="00" + num;
            n += 2;
        }
        else if (n % 3 == 2) {
            num= "0" + num;
            n++;
        }

        // add digits in group of three in gSum
        int i, GSum = 0, p = 1;
        for (i = n - 1; i >= 0; i--) {

            // group saves 3-digit group
            int group = 0;
            group += num[i--] - '0';
            group += (num[i--] - '0') * 10;
            group += (num[i] - '0') * 100;

            gSum = gSum + group * p;

            // generate alternate series of plus
            // and minus
            p *= (-1);
        }

        return (gSum % 7 == 0);
    }

    string largestPalindrome(int n, int k) {
        if(n == 1) {
            if(k == 1) return "9";
            if(k == 2) return "8";
            if(k == 3) return "9";
            if(k == 4) return "8";
            if(k == 5) return "5";
            if(k == 6) return "6";
            if(k == 7) return "7";
            if(k == 8) return "8";
            else return "9";
        } else if(n == 2) {
            if(k == 1) return "99";
            if(k == 2) return "88";
            if(k == 3) return "99";
            if(k == 4) return "88";
            if(k == 5) return "55";
            if(k == 6) return "66";
            if(k == 7) return "77";
            if(k == 8) return "88";
            else return "99";
        } else if(n == 3) {
            if(k == 1) return "999";
            if(k == 2) return "898";
            if(k == 3) return "999";
            if(k == 4) return "888";
            if(k == 5) return "595";
            if(k == 6) return "888";
            if(k == 7) return "959";
            if(k == 8) return "888";
            else return "999";
        } else {
            string ans = "";
            for(int i = 0; i < n; i++) {
                ans += '9';
            }
            if(k == 1 || k == 3 || k == 9) return ans;
            else if(k == 2) {
                ans[0] = ans[n - 1] = '8';
            } else if(k == 4) {
                ans[0] = ans[n - 1] = ans[1] = ans[n - 2] = '8';
            } else if(k == 5) {
                ans[0] = ans[n - 1] = '5';
            } else if(k == 6) {
                ans[0] = ans[n - 1] = '8';
                long long sum = 9 * n;
                sum -= 2;
                if(sum % k == 0) return ans;
                else {
                    if(n % 2) {
                        ans[n / 2] -= 1;
                    } else {
                        ans[n / 2 - 1] -= 2;
                        ans[n / 2] -= 2;
                    }
                    return ans;
                }
            } else if(k == 7) {
                for(int i = '9'; i >= '0'; i--) {
                    if(n % 2) {
                        ans[n / 2] = i;
                        if(isdivisible7(ans)) return ans;
                    } else {
                        ans[n / 2] = i;
                        ans[n / 2 - 1] = i;
                        if(isdivisible7(ans)) return ans;
                    }
                }
            } else {
                ans[0] = ans[2] = ans[n - 3] = ans[n - 1] = ans[1] = ans[n - 2] = '8';
            }
            return ans;
        }
    }
};