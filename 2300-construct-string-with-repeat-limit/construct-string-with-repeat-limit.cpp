class Solution {
public:
    typedef pair<char, int> pp;
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pp> pq;
        unordered_map<char, int> m;
        for(auto x : s) m[x]++;
        for(auto x : m) pq.push(x);
        string ans = "";
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            char ch = t.first;
            int freq = t.second;
            int x = min(freq, repeatLimit);
            for(int i = 0; i < x; i++) {
                ans += ch;
            }
            freq -= x;
            if(freq > 0) {
                if(pq.size()) {
                    auto t = pq.top();
                    pq.pop();
                    t.second -= 1;
                    ans += t.first;
                    if(t.second) pq.push(t);
                } else {
                    return ans;
                }
            }
            if(freq) pq.push({ch, freq});
        }
        return ans;
    }
};