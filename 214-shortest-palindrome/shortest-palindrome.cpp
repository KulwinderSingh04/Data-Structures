class Solution {
public:
    vector<int> fun(string s) {
        int i = 1;
        int len = 0;
        int n = s.size();
        vector<int> lps(n);
        while(i < n) {
            if(s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len == 0) i++;
                else len = lps[len -1];
            }
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        int n = s.size();
        string t1 = s;
        string t2 = t1;
        reverse(t1.begin(), t1.end());
        t2 += '#' + t1;
        vector<int> lps = fun(t2);
        string str = s.substr(lps.back());
        reverse(str.begin(), str.end());
        str += s;
        return str;
    }
};