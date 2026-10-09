class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n ; i++) {
            if(s[i] == '[') {
                st.push('[');
            } else {
                if(st.size()) st.pop();
                else st.push('[');
            }
        }
        return st.size() / 2;
    }
};