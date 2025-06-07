class Solution {
public:
    typedef pair<char, int> pp;
    class cmp {
        public:
        bool operator()(pair<char, int>& p1, pair<char, int>& p2) {
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        }
    };
    string clearStars(string s) {
        int n = s.size();
        unordered_set<int> del;
        priority_queue<pp, vector<pp>, cmp> pq;
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {
                pq.push({s[i], i});
            } else {
                del.insert(pq.top().second);
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