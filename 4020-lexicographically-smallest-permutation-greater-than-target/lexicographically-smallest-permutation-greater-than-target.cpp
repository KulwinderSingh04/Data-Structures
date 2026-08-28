class Solution {
public:
    bool fun(int i, bool g, vector<int>& cnt, string& r, string& target) {
        if(i == target.size()) return g;
        for(int ch = 'a'; ch <= 'z'; ch++) {
            if(cnt[ch - 'a'] == 0) continue;
            if(g == 0 && ch < target[i]) continue;
            int ng = g;
            if(target[i] < ch) ng = true;
            cnt[ch - 'a']--;
            r.push_back(ch);
            if(fun(i + 1, ng, cnt, r, target)) return true;
            r.pop_back();
            cnt[ch - 'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        string r = "";
        vector<int> cnt(26);
        for(auto x : s) cnt[x - 'a']++;
        if(fun(0, 0, cnt, r, target)) return r;
        return "";
    }
};