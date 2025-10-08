class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for(auto x : deadends) dead.insert(x);
        int vis[10][10][10][10] = {0};
        vis[0][0][0][0] = 1;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        while(q.size()) {
            auto t = q.front();
            q.pop();
            if(dead.find(t.first) != dead.end()) continue;
            if(t.first == target) return t.second;
            for(int i = 0; i < 4; i++) {
                string str = t.first;
                if(str[i] != '9') str[i] += 1;
                else str[i] = '0';
                if(vis[str[0] - 48][str[1] - 48][str[2] - 48][str[3] - 48] == 0) {
                    q.push({str, t.second + 1});
                    vis[str[0] - 48][str[1] - 48][str[2] - 48][str[3] - 48] = 1;
                }
                str = t.first;
                if(str[i] != '0') str[i] -= 1;
                else str[i] = '9';
                if(vis[str[0] - 48][str[1] - 48][str[2] - 48][str[3] - 48] == 0) {
                    q.push({str, t.second + 1});
                    vis[str[0] - 48][str[1] - 48][str[2] - 48][str[3] - 48] = 1;
                }
            }
        }
        return -1;
    }
};