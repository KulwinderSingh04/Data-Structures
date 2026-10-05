class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int ans = 0;
        int score = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == ')') {
                if(s[i - 1] == '(') {
                    score = st.top() + 1;
                    st.pop();
                }
                else {
                    score = 2 * score + st.top();
                    st.pop();
                }
            } else {
                st.push(score);
                score = 0;
            }
        }
        return score;
    }
};