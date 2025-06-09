class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int sz = 1;
        int si = 0;
        for(int i = 0; i < n; i++) {
            int j = i;
            int k = i;
            while(k >= 0 && j <= n) {
                if(s[k] == s[j]) {
                    if(sz < j - k + 1) {
                        si = k;
                        sz = j - k + 1;
                    }
                    k--;
                    j++;
                } else break;
            }
        }
        for(int i = 0; i < n - 1; i++) {
            int j = i;
            int k = i + 1;
            while(k >= 0 && j <= n) {
                if(s[k] == s[j]) {
                    if(sz < j - k + 1) {
                        si = k;
                        sz = j - k + 1;
                    }
                    k--;
                    j++;
                } else break;
            }
        }
        return s.substr(si, sz);
    }
};