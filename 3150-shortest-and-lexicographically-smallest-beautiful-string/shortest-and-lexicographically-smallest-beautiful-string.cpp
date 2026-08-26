class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        unordered_map<int, int> mp;
        int ans = 1e9;
        string str = "";
        int cnt = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') cnt++;
            if(mp.find(cnt - k) != mp.end()) {
                int idx = mp[cnt - k];
                if(i - idx < ans) {
                    ans = i - idx;
                    str = s.substr(idx + 1, ans);
                } else if(i - idx == ans) {
                    str = min(str, s.substr(idx + 1, ans));
                }
            }
            mp[cnt] = i;
        }
        return str;
    }
};