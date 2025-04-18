class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string t = countAndSay(n - 1);
        int freq = 0;
        char ch = t[0];
        string ans = "";
        for(int i = 0; i < t.size(); i++) {
            if(t[i] == ch) freq++;
            else {
                ans += freq + 48;
                ans += ch;
                ch = t[i];
                freq = 1;
            }
        }
        ans += freq + 48;
        ans += ch;
        return ans;
    }
};