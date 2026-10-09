class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push('(');
            } else {
                int c = 1;
                if(i < n - 1 && s[i + 1] == ')') {
                    c++;
                    i++;
                }
                if(st.size()) {
                    ans += 2 - c;
                    st.pop();
                } else {
                    ans += 2 - c + 1;
                }
            }
        }
        ans += 2 * st.size();
        return ans;
    }
};