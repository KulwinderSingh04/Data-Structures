class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for(int i1 = 0; i1 < 26; i1++) {
            char ch1 = i1 + 'a';
            for(int i2 = 0; i2 < 26; i2++) {
                if(i1 == i2) continue;
                char ch2 = i2 + 'a';
                for(int pass = 0; pass < 2; pass++) {
                    int c1 = 0, c2 = 0;
                    for(int j = 0; j < s.size(); j++) {
                        if(ch1 == s[j]) c1++;
                        if(ch2 == s[j]) c2++;
                        if(c2 > 0) ans = max(ans, c1 - c2);
                        if(c1 - c2 < 0) c1 = c2 = 0;
                    }
                    reverse(s.begin(), s.end());
                }
            }
        }
        return ans;
    }
};