class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& dict) {
        unordered_set<string> s;
        for(auto x : dict) s.insert(x);
        queue<pair<string, int>> q;
        q.push({begin, 1});
        s.erase(begin);
        int ans = 0;
        while(q.size()) {
            auto a = q.front();
            string t = a.first;
            int time = a.second;
            if(end == t) ans = time;
            q.pop();
            for(int i = 0; i < t.size(); i++) {
                string str = t;
                for(int j = 0; j < 26; j++) {
                    str[i] = j + 'a';
                    if(s.find(str) != s.end()) {
                        q.push({str, time + 1});
                        s.erase(str);
                    }
                }
            }
        }
        return ans;
    }
};