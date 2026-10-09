class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                cnt++;
            } else {
                int c = 1;
                if(i < n - 1 && s[i + 1] == ')') {
                    c++;
                    i++;
                }
                if(cnt) {
                    ans += 2 - c;
                    cnt--;
                } else {
                    ans += 2 - c + 1;
                }
            }
        }
        ans += 2 * cnt;
        return ans;
    }
};