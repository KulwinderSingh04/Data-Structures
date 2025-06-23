class Solution {
public:
    bool isPal(long long num, int k) {
        string a = "";
        while(num) {
            a += ((num % k) + 48);
            num /= k;
        }
        string b = a;
        reverse(b.begin(), b.end());
        return a == b;
    }
    long long kMirror(int k, int n) {
        long long ans = 0;
        for(int len = 1; len < 1000; len++) {
            int half = (len + 1) / 2;
            for(int i = pow(10, half - 1); i < pow(10, half); i++) {
                if(n == 0) return ans;
                string s = to_string(i);
                reverse(s.begin(), s.end());
                string num = "";
                if(len % 2 == 0) {
                    num = to_string(i) + s;
                } else {
                    s.erase(s.begin());
                    num = to_string(i) + s;
                }

                if(isPal(stoll(num), k)) {
                    n--;
                    ans += stoll(num);
                }
            } 
        }
        return ans;
    }
};