class Solution {
public:
    typedef pair<int, int> pp;
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        int n = hand.size();
        if(n % groupSize != 0) return false;
        for(int i = 0; i < n; i++) m[hand[i]]++;
        while(m.size()) {
            auto t = m.begin() -> first;
            for(int i = 0; i < groupSize; i++) {
                if(m.find(t) != m.end()) {
                    m[t] -= 1;
                    if(m[t] == 0) m.erase(t);
                    t = t + 1;
                }
                else return false;
            }
        }
        return true;
    }
};