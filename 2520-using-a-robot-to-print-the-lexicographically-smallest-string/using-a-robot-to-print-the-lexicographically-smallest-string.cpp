class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        char mn = 'z';
        vector<char> v(n);
        for(int i = n - 1; i >=0; i--) {
            mn = min(s[i], mn);
            v[i] = mn;
        }
        string ans = "";
        stack<char> st;
        for(int i = 0; i < n; i++) {
            st.push(s[i]);
            while(st.size() && (i + 1 >= n || v[i + 1] >= st.top())) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};