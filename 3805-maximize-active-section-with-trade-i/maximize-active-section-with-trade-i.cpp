class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> v;
        int n = s.size();
        int cnt = 1;
        string str = "";
        str += s[0];
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) cnt++;
            else {
                str += s[i];
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);
        int c1 = 0;
        for(auto x : s) c1 += (x == '1');
        int ans = c1;
        for(int i = 1; i < v.size() - 1; i++) {
            if(str[i] == '1') {
                int a = 0;
                if(i - 1 >= 0 && i + 1 < v.size()) {
                    a = v[i] + v[i - 1] + v[i + 1];
                    ans = max(ans, a + c1 - v[i]);
                }
            }
        }
        return ans;
    }
};