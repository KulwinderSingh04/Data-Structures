class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        vector<int> v(26);
        int res = INT_MAX;
        for(auto x : word) v[x - 97]++;
        for(int i = 0; i < 26; i++) {
            if(v[i] == 0) continue;
            int ans = 0;
            for(int j = 0; j < 26; j++) {
                if(v[j] == 0) continue;
                if(v[j] < v[i]) {
                    ans += v[j];
                } else if(v[j] > v[i] + k) {
                    ans += v[j] - v[i] - k;
                }
            }
            res = min(ans, res);
        }
        return res;
    }
};