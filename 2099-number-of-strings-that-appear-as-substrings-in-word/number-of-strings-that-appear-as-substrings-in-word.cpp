class Solution {
public:
    vector<int> fun(string& patt) {
        int n = patt.size();
        int j = 1;
        int len = 0;
        vector<int> lps(n);
        while(j < n) {
            if(patt[j] == patt[len]) {
                lps[j] = len + 1;
                len++;
                j++;
            } else {
                if(len) {
                    len = lps[len - 1];
                } else {
                    j++;
                }
            }
        }
        return lps;
    }
    bool match(string& word, string& patt) {
        vector<int> lps = fun(patt);
        int n1 = word.size();
        int n2 = patt.size();
        int i = 0, j = 0;
        while(i < n1) {
            if(word[i] == patt[j]) {
                i++;
                j++;
                if(j == n2) return true;
            } else {
                if(j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto x : patterns) {
            if(match(word, x)) cnt++;
        }
        return cnt;
    }
};