class Solution {
public:
    typedef pair<int, char> pp;
    int minDeletion(string s, int k) {
        map<char, int> m;
        for(auto x : s) m[x]++;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(auto x : m) pq.push({x.second, x.first});
        int ans = 0;
        while(pq.size() > k) {
            auto t = pq.top();
            pq.pop();
            ans += t.first;
        }
        return ans;
    }
};