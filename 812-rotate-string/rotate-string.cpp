class Solution {
public:
    void fun(string& pat, vector<int>& lps) {
        int n = pat.size();
        int j = 1;
        int len = 0;
        while(j < n) {
            if(pat[j] == pat[len]) {
                len++;
                lps[j] = len;
            } else {
                if(len != 0) len = lps[len - 1];
            }
            j++;
        }
    }
    bool kmp(string& txt, string& pat) {
        int nt = txt.size(), np = pat.size();
        vector<int> lps(np);
        fun(pat, lps);
        int i = 0, j = 0;
        while(i < nt) {
            if(txt[i] == pat[j]) {
                i++;
                j++;
                if(j == np) return true;
            } else {
                if(j == 0) i++;
                else j = lps[j - 1];
            }
        }
        return false;
    }
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        s += s;
        return kmp(s, goal);
    }
};