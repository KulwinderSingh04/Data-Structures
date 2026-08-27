class Solution {
public:
    bool f(int i, string &t, vector<int> &cnt, string &r, bool g) {
        if (i == t.size()) return g;
        for (int c = 0; c < 26; c++) {
            if (!cnt[c]) continue;
            char ch = 'a' + c;
            if (!g && ch < t[i]) continue;
            bool ng = g || ch > t[i];
            cnt[c]--;
            r.push_back(ch);
            if (f(i + 1, t, cnt, r, ng)) return true;
            r.pop_back();
            cnt[c]++;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string t) {
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        string r;
        if (f(0, t, cnt, r, false)) return r;
        return "";
    }
};