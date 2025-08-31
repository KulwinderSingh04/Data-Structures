class Solution {
public:
    bool fun(string& s, string& t) {
        int n = s.size();
        unordered_map<char, char> mp;
        for(int i = 0; i < n; i++) {
            if(mp.find(s[i]) != mp.end()) {
                if(mp[s[i]] != t[i]) return false;
            } else {
                mp[s[i]] = t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return fun(s, t) && fun(t, s);
    }
};