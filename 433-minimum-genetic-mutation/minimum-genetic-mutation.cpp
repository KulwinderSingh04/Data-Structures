class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        unordered_set<string> s;
        for(auto x : bank) s.insert(x);
        q.push({startGene, 0});
        while(q.size()) {
            auto t = q.front();
            q.pop();
            if(t.first == endGene) return t.second;
            for(int i = 0; i < 8; i++) {
                string str = t.first;
                vector<char> v = {'A', 'C', 'G', 'T'};
                for(int j = 0; j < 4; j++) {
                    if(v[j] == str[i]) continue;
                    str[i] = v[j];
                    if(s.find(str) != s.end()) {
                        q.push({str, t.second + 1});
                        s.erase(str);
                    }
                }
            }
        }
        return -1;
    }
};