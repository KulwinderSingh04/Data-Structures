class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        int n = word1.size();
        unordered_map<int, int> m1, m2;
        for(int i = 0; i < n; i++) {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        unordered_map<int, int> t1, t2;
        for(auto x : m1) {
            if(m2.find(x.first) == m2.end()) return false;
            t1[x.second]++;
        }
        for(auto x : m2) {
            t2[x.second]++;
        }
        return t1 == t2;
    }
};