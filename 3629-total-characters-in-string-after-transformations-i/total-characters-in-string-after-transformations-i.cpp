class Solution {
public:
    int MOD = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        long long ans = 0;
        vector<long long> m(26);
        for(auto x : s) {
            m[x - 97]++;
        }
        while(t--) {
            vector<long long> m1(26);
            for(int i = 0; i < 26; i++) {
                if(m[i] == 0) continue;
                if(i != 25) {
                    m1[i + 1] += m[i];
                    m1[i + 1] %= MOD;
                }
                else {
                    m1['a' - 97] += m[25];
                    m1['b' - 97] += m[25];
                    m1['a' - 97] %= MOD;
                    m1['b' - 97] %= MOD;
                }
            }
            m = move(m1);
        }
        for(auto x : m) {
            ans += x;
            ans %= MOD;
        }
        return ans;
    }
};