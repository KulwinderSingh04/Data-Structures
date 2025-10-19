class Solution {
public:
    bool fun(int i, string& a, string& t, vector<int>& mp, bool flag) {
        if(a.size() == t.size()) return flag;
        for(int c = 0; c < 26; c++) {
            if(mp[c] == 0) continue;
            char ch = 'a' + c;
            if(!flag && ch < t[i]) continue;
            bool ng = flag || ch > t[i];
            mp[c]--;
            a.push_back(ch);
            bool f = fun(i + 1, a, t, mp, ng);
            if(f) return f;
            a.pop_back();
            mp[c]++;
            
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> mp(26);
        for(auto x : s) mp[x - 'a']++;
        string a = "";
        bool flag = false;
        bool f = fun(0, a, target, mp, flag);
        if(f) return a;
        return "";
    }
};