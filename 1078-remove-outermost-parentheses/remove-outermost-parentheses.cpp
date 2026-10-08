class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                if(cnt) ans += s[i];
                cnt++;
            } else {
                if(cnt > 1) ans += s[i];
                cnt--;
            }
        }
        return ans;
    }
};