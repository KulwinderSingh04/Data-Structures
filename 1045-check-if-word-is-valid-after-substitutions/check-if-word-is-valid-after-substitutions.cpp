class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        int i = 3;
        int j = 3;
        while(j < n) {
            if(i - 3 >= 0 && s[i - 1] == 'c' && s[i - 2] == 'b' && s[i - 3] == 'a') {
                i -= 3;
            }
            s[i] = s[j];
            j++;
            i++;
        }
        if(s.substr(0, i) == "abc") return true;
        return false;
    }
};