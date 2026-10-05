class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int cnt = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' && s[i + 1] == ')') {
                ans += (1 << cnt);
            }
            if(s[i] == '(') cnt++;
            else cnt--;
        }
        return ans;
    }
};