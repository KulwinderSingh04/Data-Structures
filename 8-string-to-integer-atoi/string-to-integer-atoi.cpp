class Solution {
public:
    int myAtoi(string s) {
        while(s[0] == ' ') s.erase(s.begin());
        int sign = 1;
        int idx = 0;
        if(s[0] == '-') {
            idx = 1;
            sign = -1;
        } else if(s[0] == '+') idx = 1;
        int n = s.size();
        long long ans = 0;
        for(int i = idx; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                // cout << s[i] - 48<< " ";
                ans = ans * 10 + (s[i] - 48);
                // cout << ans << endl;
                if(ans * sign <= INT_MIN) return INT_MIN;
                if(ans * sign >= INT_MAX) return INT_MAX;
            } else break;
        }
        return ans * sign;
    }
};