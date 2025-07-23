class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans1 = 0, ans2 = 0;
        int n = s.size();
        if(x > y) {
            stack<char> st;
            for(int i = 0; i < n; i++) {
                if(s[i] == 'b' && st.size() && st.top() == 'a') {
                    ans1 += x;
                    st.pop();
                }
                else st.push(s[i]);
            }
            string str = "";
            while(st.size()) {
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());
            for(int i = 0; i < str.size(); i++) {
                if(str[i] == 'a' && st.size() && st.top() == 'b') {
                    ans1 += y;
                    st.pop();
                }
                else st.push(str[i]);
            }
            return ans1;
        } else {
            stack<char> st;
            for(int i = 0; i < n; i++) {
                if(s[i] == 'a' && st.size() && st.top() == 'b') {
                    ans2 += y;
                    st.pop();
                }
                else st.push(s[i]);
            }
            string str = "";
            while(st.size()) {
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());
            for(int i = 0; i < str.size(); i++) {
                if(str[i] == 'b' && st.size() && st.top() == 'a') {
                    ans2 += x;
                    st.pop();
                }
                else st.push(str[i]);
            }
            return ans2;
        }
        // return max(ans1, ans2);
    }
};