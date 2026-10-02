class Solution {
public:
    void fun(int n, int o, int c, vector<string>& v, string str) {
        if(c == n) {
            v.push_back(str);
            return;
        }
        if(o < n) fun(n, o + 1, c, v, str + '(');
        if(o > c) fun(n, o, c + 1, v, str + ')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        fun(n, 0, 0, v, "");
        return v;
    }
};