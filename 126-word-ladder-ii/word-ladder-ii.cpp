class Solution {
public:
    typedef pair<string, int> pp;
    void dfs(string word, int len, string target, unordered_map<string, int>& mp, vector<string>& v, vector<vector<string>>& ans) {
        string str = word;
        if(target == str) {
            reverse(v.begin(), v.end());
            ans.push_back(v);
            reverse(v.begin(), v.end());
            return;
        }
        for(int i = 0; i < word.size(); i++) {
            for(int j = 0; j < 26; j++) {
                str[i] = j + 'a';
                if(mp.count(str) && mp[str] == len - 1) {
                    v.push_back(str);
                    dfs(str, len - 1, target, mp, v, ans);
                    v.pop_back();
                }
                str[i] = word[i];
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        mp[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> s;
        for(auto x : wordList) s.insert(x);
        s.erase(beginWord);
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int steps = mp[t];
            if(t == endWord) break;
            for(int i = 0; i < t.size(); i++) {
                string str = t;
                for(int j = 0; j < 26; j++) {
                    str[i] = j + 'a';
                    if(str != t && s.find(str) != s.end()) {
                        q.push(str);
                        mp[str] = steps + 1;
                        s.erase(str);
                    }
                }
            }
        }
        vector<vector<string>> ans;
        vector<string> v;
        if(mp.find(endWord) != mp.end()) {
            v.push_back(endWord);
            dfs(endWord, mp[endWord], beginWord, mp, v, ans);
        }
        return ans;
    }
};