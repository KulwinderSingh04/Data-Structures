class Solution {
public:
    bool isValid(string str) {
        int n = str.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[') ans.push_back(str[i]);
            else {
                if(ans.size() == 0) return false;
                if(str[i] == ')') {
                    if(ans.size() && ans.back() != '(') return false;
                    else ans.pop_back();
                }
                else if(str[i] == ']') {
                    if(ans.size() && ans.back() != '[') return false;
                    else ans.pop_back();
                }
                else {
                    if(ans.size() && ans.back() != '{') return false;
                    else ans.pop_back();
                }
            }
        }
        return ans.size() == 0;
    }
};