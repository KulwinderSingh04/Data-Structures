class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size() + 2;
        reverse(s.begin(), s.end());
        s.push_back('1');
        reverse(s.begin(), s.end());
        s.push_back('1');
        int c1 = 0;
        int c0 = 0;
        int a = 0;
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                a++;
                c1++;
                if(c0 != 0) {
                    ans.push_back({0, c0});
                    c0 = 0;
                }
            }
            else {
                c0++;
                if(c1 != 0) {
                    ans.push_back({1, c1});
                    c1 = 0;
                }
            }
        }
        if(c1 != 0) {
            ans.push_back({1, c1});
            c1 = 0;
        }
        int res = 0;
        // for(int i = 0; i < n; i++) cout << ans[i].first << " " << ans[i].second << endl;
        for(int i = 1; i < ans.size(); i += 2) {
            if(i + 2 < ans.size()) res = max(ans[i].second + ans[i + 2].second, res);
        }
        return res + a - 2;
    }
};