class Solution {
public:
    void lps(string& pat, vector<int>& v) {
        int n = pat.size();
        int len = 0;
        v[0] = 0;
        int i = 1;
        while(i < n) {
            if(pat[i] == pat[len]) {
                len++;
                v[i] = len;
                i++;
            } else {
                if(len == 0) {
                    i++;
                    v[i - 1] = 0;
                }
                else len = v[len - 1];
            }
        }
    }
    bool search(string& pat, string& txt) {
        cout << pat << " " << txt;
        // code here
        int n = txt.size();
        vector<int> v(pat.size());
        lps(pat, v);
        int i = 0;
        int j = 0;
        vector<int> res;
        while(i < txt.size()) {
            if(txt[i] == pat[j]) {
                i++;
                j++;
                if(j == pat.size()) {
                    return true;
                }
            }
            else {
                if(j != 0) j = v[j - 1];
                else i++;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(search(b, a)) return 1;
        int n = a.size();
        int m = b.size();
        string str = a;
        int c = 1;
        while(str.size() < b.size()) {
            c++;
            str += a;
        }
        bool f = search(b, str);
        if(f) return c;
        str += a;
        f = search(b, str);
        return f ? c + 1 : -1;

    }
};