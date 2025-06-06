class Solution {
public:
    string robotWithString(string s) {
        vector<int> hash(26);
        int n = s.size();
        for(int i = 0; i < n; i++) hash[s[i] - 97]++;
        int j = 0;
        stack<char> st;
        char mn = 'a';
        string ans = "";
        for(int i = 0; i < n; i++) {
            st.push(s[i]);
            hash[s[i] - 97]--;
            while(mn != 'z' && hash[mn - 97] == 0) mn++;
            while(st.size() && st.top() <= mn) {
                ans += st.top();
                st.pop();
            }
        }
        while(st.size()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};