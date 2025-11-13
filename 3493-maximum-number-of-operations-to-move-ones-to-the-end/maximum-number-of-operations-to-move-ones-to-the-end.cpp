class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int count = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') count++;
            else if(s[i] == '0' && (i == n - 1 || s[i + 1] == '1')) {
                ans += count;
            }
        }
        return ans;
    }
};