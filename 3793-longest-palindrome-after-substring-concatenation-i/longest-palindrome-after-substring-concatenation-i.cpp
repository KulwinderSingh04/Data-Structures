class Solution {
public:
    int longestPalindrome(string s, string t) {
        int n = s.size();
        int m = t.size();
        int ans = 1;
        for(int i = 0; i < n; i++) {
            string a1 = "";
            for(int j = i; j < n; j++) {
                a1 += s[j];
                for(int k = 0; k < m; k++) {
                    string a2 = "";
                    for(int l = k; l < m; l++) {
                        a2 += t[l];
                        string z = a1 + a2; 
                        string x = z;
                        // cout << a1 << " " << a2 << endl;
                        reverse(x.begin(), x.end());
                        if(x == z) ans = max(ans, (int)z.size());
                        else {
                            string z1 = a1;
                            reverse(z1.begin(), z1.end());
                            string z2 = a2;
                            reverse(z2.begin(), z2.end());  
                            if(z1 == a1) ans = max(ans, (int)z1.size());
                            if(z2 == a2) ans = max(ans, (int)z2.size());
                        }
                    }
                }
            }
        }
        return ans;
    }
};