class Solution {
public:
    int fun(int i, int j, string& s) {
        int n = s.size();
        while(i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
        }
        // if(i < 0 && j >= n) return j - i - 1;
        return j - i - 1;
    }
    int almostPalindromic(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int j = i, k = i;
            while(j >= 0 && k < n) {
                if(s[j] == s[k]) {
                    j--;
                    k++;
                } else break;
            }
            if(j < 0 && k >= n) {
                ans = max(ans, k - j - 1);
            } else if(j < 0 || k >= n) {
                ans = max(ans, k - j);
            } else {
                ans = max(ans, fun(j - 1, k, s));
                ans = max(ans, fun(j, k + 1, s));
            }
            j = i, k = i + 1;
            while(j >= 0 && k < n) {
                if(s[j] == s[k]) {
                    j--;
                    k++;
                } else break;
            }
            if(j < 0 && k >= n) {
                ans = max(ans, k - j - 1);
            } else if(j < 0 || k >= n) {
                ans = max(ans, k - j);
            } else {
                ans = max(ans, fun(j - 1, k, s));
                ans = max(ans, fun(j, k + 1, s));
            }
            cout << ans << endl;
            // if(i == 3) cout << j << " " << k <<  " " << flag << endl;
            // if(j < 0 && k >= n) {
            //     ans = max(ans, k - j - 1);
            //     continue;
            // }
            // if(flag) ans = max(ans, min(n, k - j));
        }
        return ans;
    }
};