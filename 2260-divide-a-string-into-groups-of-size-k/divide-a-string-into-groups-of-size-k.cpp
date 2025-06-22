class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        for(int i = 0; i < s.size() % k; i++) s.push_back(fill);
        vector<string> ans;
        for(int i = 0; i < s.size(); i += k) {
            ans.push_back(s.substr(i, k));
        }
        return ans;
    }
};