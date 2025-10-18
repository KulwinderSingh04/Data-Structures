class Solution {
public:
    void fun(int& n, string str, vector<string>& ans) {

        if(n == str.size()) {
            ans.push_back(str);
            return;
        }
        if(str.size() == 0 || str.back() == '1') {
            fun(n, str + '0', ans);
        }
        fun(n, str + '1', ans);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string str = "";
        fun(n, str, ans);
        return ans;
    }
};