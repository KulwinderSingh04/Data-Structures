class Solution {
public:
    typedef pair<int, int> pp;
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        map<vector<int>, int> m;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dominoes[i][0] > dominoes[i][1]) swap(dominoes[i][0], dominoes[i][1]);
            if(m.find(dominoes[i]) != m.end()) {
                ans += m[dominoes[i]];
            }
            m[dominoes[i]]++;
        }
        return ans;
    }
};