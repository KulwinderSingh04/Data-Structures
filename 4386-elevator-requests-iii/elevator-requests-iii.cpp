class Solution {
public:
    typedef long long ll;
    long long elevatorRequests(int n, int start, vector<vector<int>>& req) {
        int sz = req.size();
        vector<vector<ll>> dp((1 << sz), vector<ll> (sz, 1e18));
        for(int l = 0; l < sz; l++) {
            dp[1 << l][l] = max(abs(start - req[l][1]), req[l][0]);
        }
        for(int mask = 1; mask < (1 << sz) - 1; mask++) {
            for(int last = 0; last < sz; last++) { 
                if((mask & (1 << last))) continue;
                int newMask = mask | (1 << last);
                for(int i = 0; i < sz; i++) {
                    if((mask & (1 << i)) == 0) continue;
                    dp[newMask][last] = min(dp[newMask][last], max(abs(req[i][1] - req[last][1]) + dp[mask][i], 1LL * req[last][0]));
                }
            }
        }
        ll ans = 1e18;
        for(int i = 0; i < sz; i++) {
            ans = min(ans, dp[(1 << sz) - 1][i]);
        }
        return ans;
    }
};