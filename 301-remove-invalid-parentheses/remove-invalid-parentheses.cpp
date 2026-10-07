class Solution {
public:
    void fun(int i, int rem, int cnt, string& s, string& str, unordered_set<string>& res) {
        int n = s.size();
        if(i == n) {
            if(cnt == 0) {
                res.insert(str);
            }
            return;
        }
        if(s[i] == '(') {
            str += '(';
            fun(i + 1, rem, cnt + 1, s, str, res);
            str.pop_back();
            if(rem) fun(i + 1, rem - 1, cnt, s, str, res);
        } else if(s[i] == ')') {
            str += ')';
            if(cnt) fun(i + 1, rem, cnt - 1, s, str, res);
            str.pop_back();
            if(rem) fun(i + 1, rem - 1,  cnt, s, str, res);
        } else {
            str += s[i];
            fun(i + 1, rem, cnt, s, str, res);
            str.pop_back();
        }
    
    }
    vector<string> removeInvalidParentheses(string s) {
        int cnt = 0;
        int ans = 0;
        for(auto x : s) {
            if(x == '(') {
                cnt++;
            } else if(x == ')') {
                if(cnt) cnt--;
                else ans++;
            }
        }
        ans += cnt;
        if(ans == 0) return {s};
        unordered_set<string> st;
        string str = "";
        fun(0, ans, 0, s, str, st);
        vector<string> res(st.begin(), st.end());
        return res;
    }
};