class Solution {
public:
    typedef pair<string, int> pp;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pp> q;
        unordered_set<string> s;
        for(int i = 0; i < wordList.size(); i++) s.insert(wordList[i]);
        q.push({beginWord, 1});
        int ans = 0;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            if(t.first == endWord) {
                ans = t.second;
                break;
            }
            for(int i = 0; i < t.first.size(); i++) {
                string str = t.first;
                for(int j = 0; j < 26; j++) {
                    str[i] = j + 97;
                    if(s.find(str) != s.end()) {
                        q.push({str, t.second + 1});
                        s.erase(str);
                    }
                }
            }
        }
        return ans;
    }
};