class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<int> st;
        for(auto x : s) {
            if(x == '(') {
                st.push('(');
                ans = max(ans, (int)st.size());
            } else if(x == ')') {
                st.pop();
            }
        }
        return ans;
    }
};