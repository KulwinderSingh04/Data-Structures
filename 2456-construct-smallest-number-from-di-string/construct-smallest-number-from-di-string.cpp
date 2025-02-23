class Solution {
public:
    string smallestNumber(string pattern) {
        int n =  pattern.size();
        stack<int> st;
        int count = 1;
        string ans = "";
        st.push(1);
        for(int i = 0; i < n; i++) {
            if(pattern[i] == 'I') {
                while(st.size()) {
                    ans.push_back(st.top() + 48);
                    st.pop();
                }
            }
            count++;
            st.push(count);
        }
        while(st.size()) {
            ans.push_back(st.top() + 48);
            st.pop();
        }
        return ans;
    }
};