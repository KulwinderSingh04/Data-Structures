class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> m1, m2;
        int v = 0, c =  0;
        for(auto x : s) {
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                m1[x]++;
                v = max(v, m1[x]);
            } else {
                m2[x]++;
                c = max(c, m2[x]);
            }
        }
        return c + v;
    }
};