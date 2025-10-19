class Solution {
public:
    void rev(string& s, int k) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + k);
        reverse(s.begin() + k, s.end());
    }
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        queue<string> q;
        unordered_set<string> vis;
        vis.insert(s);
        q.push(s);
        string ans = "";
        while(q.size()) {
            auto t = q.front();
            q.pop();
            if(ans == "" || t < ans) ans = t;
            string str = t;
            for(int i = 1; i < t.size(); i += 2) {
                str[i] = 48 + (str[i] - 48 + a) % 10;
            }
            if(vis.find(str) == vis.end()) {
                q.push(str);
                vis.insert(str);
            }
            str = t;
            rev(str, b);
            if(vis.find(str) == vis.end()) {
                q.push(str);
                vis.insert(str);
            }
        }
        return ans;
    }
};