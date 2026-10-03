class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<pair<int, int>> st;
        // st.push();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push({i, '('});
            } else {
                if(st.size() && st.top().second == '(') {
                    st.pop();
                    int v = i;
                    if(st.size()) v -= st.top().first;
                    else v++;
                    ans = max(ans, v);
                } else {
                    st.push({i, ')'});
                }
            }
        }
        return ans;
    }
};