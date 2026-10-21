class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());
        if(s == t) return 0;
        if(n == 2) return -1;
        if(s[0] == t[0] || s.back() == t.back()) return 1;
        vector<int> mp(26);
        for(auto x : s) mp[x - 97]++;
        if(mp[s[0] - 97] == 1 && mp[s[n - 1] - 97] == 1 && s[0] == t[n - 1] && t[0] == s[n - 1]) return 3;
        return 2;
    }
};