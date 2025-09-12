class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count++;
        if(count == 0) return false;
        return true;
    }
};