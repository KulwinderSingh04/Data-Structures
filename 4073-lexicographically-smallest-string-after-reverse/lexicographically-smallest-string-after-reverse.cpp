class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        string t = s;
        int n = s.size();
        for(int k = 0; k < n; k++) {
            reverse(t.begin(), t.begin() + k + 1);
            ans = min(ans, t);
            t = s;
            reverse(t.begin() + k + 1, t.end());
            ans = min(ans, t);
            t = s;
        }
        return ans;
    }
};