class Solution {
public:
    int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        map<long long, long long> mp;
        for(auto x : points) {
            mp[x[1]]++;
        }
        long long prev = 0;
        long long ans = 0;
        for(auto x : mp) {
            long long lines = x.second;
            long long hor =((lines * (lines - 1)) % MOD) / 2;
            ans += hor * prev;
            ans %= MOD;
            prev += hor;
        }
        return ans;
    }
};