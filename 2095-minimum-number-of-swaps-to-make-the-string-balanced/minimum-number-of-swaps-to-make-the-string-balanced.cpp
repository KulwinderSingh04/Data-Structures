class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i = 0; i < n ; i++) {
            if(s[i] == '[') {
                cnt++;
            } else {
                if(cnt) cnt--;
                else cnt++;
            }
        }
        return cnt / 2;
    }
};