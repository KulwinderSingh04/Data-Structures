class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        int n = knowledge.size();
        for(int i = 0; i < n; i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        int sz = s.size();
        int i = 0;
        string ans = "";
        while(i < sz) {
            if(s[i] == '(') {
                string key = "";
                i++;
                while(s[i] != ')') key += s[i++];
                if(mp.find(key) != mp.end()) ans += mp[key];
                else ans += '?';
            }
            else ans += s[i];
            i++;
        }
        return ans;
    }
};