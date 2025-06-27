class Solution {
public:
    bool isSubsequence(string s, string word) {
        int n = word.size();
        int j = 0, count = 0;
        for(int i = 0; i < n; i++) {
            if(word[i] == s[j]) {
                j++;
                if(j == s.size()) return true;
            }
        }
        return j == s.size();
    }
};