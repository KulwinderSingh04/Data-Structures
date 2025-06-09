class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push('(');
                if(st.size() > 1) ans += st.top();
            }
            else {
                if(st.size() > 1) ans += ')';
                st.pop();
            }
        }
        return ans;
    }
};