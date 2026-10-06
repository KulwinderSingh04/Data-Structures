class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int ans = 0;
        for(auto x : s) {
            if(x == '(') {
                cnt++;
            } else {
                if(cnt) cnt--;
                else ans++;
            }
        }
        return ans + cnt;
    }
};