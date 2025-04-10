class Solution {
public:
    long long fun(string str, int limit, string& s) {
        int n1 = str.size();
        int s1 = s.size();
        if(s1 > n1) return 0;
        long long ans = 0;
        string conStr = str.substr(n1 - s1);
        string remStr = str.substr(0, n1 - s1);
        for(int i = 0; i < n1 - s1; i++) {
            int digit = remStr[i] - 48;
            if(digit > limit) {
                ans += pow(limit + 1, n1 - s1 - i);
                return ans;
            }
            else {
                ans += digit * pow(limit + 1, n1 - s1 - i - 1);
            }
        }
        if(s <= conStr) return ans + 1;
        return ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start - 1);
        string finStr = to_string(finish);
        return fun(finStr, limit, s) - fun(startStr, limit, s);
    }
};