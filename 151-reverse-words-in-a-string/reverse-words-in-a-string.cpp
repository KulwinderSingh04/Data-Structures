class Solution {
public:
    string reverseWords(string s) {
        while(s[0] == ' ') s.erase(s.begin());
        int i = 0;
        while(i < s.size()) {
            if(s[i] == ' ') {
                while(i + 1 < s.size() && (s[i + 1] == ' ')) s.erase(s.begin() + i + 1);
                if(i + 1 == s.size()) break;
                i++;
                // cout << s << endl;
            } else i++;
        }
        if(s.back() == ' ') s.pop_back();
        int j = 0;
        int n = s.size();
        for(int i = 0; i <= n; i++) {
            if(i == n || s[i] == ' ') {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};