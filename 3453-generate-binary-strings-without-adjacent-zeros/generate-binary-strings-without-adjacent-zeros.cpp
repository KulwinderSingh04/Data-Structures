class Solution {
public:
    void fun(int& n, string& str, vector<string>& ans) {

        if(n == str.size()) {
            ans.push_back(str);
            return;
        }
        if(str.size() == 0 || str.back() == '1') {
            str.push_back('0');
            fun(n, str, ans);
            str.pop_back();
        }
        str.push_back('1');
        fun(n, str, ans);
        str.pop_back();
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string str = "";
        fun(n, str, ans);
        return ans;
    }
};