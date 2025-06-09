class Solution {
public:
    int maxDepth(string s) {
        int x = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                x++;
                ans = max(ans, x);
            } else if(s[i] == ')') {
                x--;
            }
        }
        return ans;
    }
};