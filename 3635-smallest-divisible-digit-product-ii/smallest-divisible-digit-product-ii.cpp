class Solution {
public:
    typedef long long ll;
    string fun(ll num, int len) {
        string str = "";
        for(int digit = 9; digit > 1; digit--) {
            while(num % digit == 0) {
                str += (digit + '0');
                num /= digit;
            }
        }
        while(str.size() < len) str += '1';
        reverse(str.begin(), str.end());
        return str;
    }
    string smallestNumber(string num, long long t) {
        int n = num.size();
        ll temp = t;
        for(int p : {2, 3, 5, 7}) {
            while(temp % p == 0) {
                temp /= p;
            }
        }
        if(temp != 1) return "-1";
        vector<ll> remFactors(n + 1, t);
        for(int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            if(digit == 0) break;
            remFactors[i + 1] = remFactors[i] / gcd(1LL * digit, remFactors[i]);
        }
        if(remFactors[n] == 1) { 
            return num;
        }
        int zeroPos = num.find('0');
        int zeroIdx= n - 1;
        if(zeroPos != -1) {
            zeroIdx = zeroPos;
        }
        for(int i = zeroIdx; i >= 0; i--) {
            ll req = remFactors[i];
            int freeSlots = n - 1 - i;
            for(int digit = (num[i] - '0') + 1; digit <= 9; digit++) {
                ll furtherReq = req / gcd(digit, req);
                string str = fun(furtherReq, freeSlots);
                if(str.size() == freeSlots) {
                    return num.substr(0, i) + char('0' + digit) + str;
                }
            }
        }
        return fun(t, n + 1);
    }
};