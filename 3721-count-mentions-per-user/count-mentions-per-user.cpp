bool cmp(vector<string> e1, vector<string> e2) {
    if(stoi(e1[1]) == stoi(e2[1])) {
        if(e1[0] == "OFFLINE") return true;
        else return false;
    }
    return stoi(e1[1]) < stoi(e2[1]);
}
class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> m(n);
        vector<int> v(n, 0);
        int e = events.size();
        sort(events.begin(), events.end(), cmp);
        for(auto event : events) {
            if(event[0] == "MESSAGE") {
                if(event[2] == "HERE") {
                    int time = stoi(event[1]);
                    for(int i = 0; i < n; i++) {
                        if(v[i] <= time) m[i]++;
                    }
                }
                else if(event[2] == "ALL") {
                    for(int i = 0; i < n; i++) {
                        m[i]++;
                    }
                }
                else {
                    int j = 0;
                    for(int i = 0; i < event[2].size(); i++) {
                        if(event[2][i] == 'd') j = i;
                        if(event[2][i] == ' ') {
                            int id = stoi(event[2].substr(j + 1, i - j + 1));
                            m[id]++;
                        }
                    }
                    int id = stoi(event[2].substr(j + 1, event[2].size() - j + 1));
                    m[id]++;
                }      
            }
            else {
                int idx = stoi(event[2]);
                v[idx] = stoi(event[1]) + 60;
            }
        }
        return m;
    }
};