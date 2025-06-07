class Solution {
public:
    typedef pair<char, int> pp;
    string clearStars(string s) {
        int n = s.size();
        unordered_set<int> del;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {
                pq.push({s[i], -i});
            } else {
                del.insert(-1 * pq.top().second);
                pq.pop();
            }
        }
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(del.find(i) == del.end() && s[i] != '*') ans += s[i];
        }
        return ans;
    }
};