class Solution {
public:
    typedef long long ll;
    ll fun(int mask, int last, int start, vector<vector<int>>& req, vector<vector<ll>>& dp) {
        int prevMask = mask ^ (1 << last);
        int n = req.size();
        if(prevMask == 0) {
            return max(abs(start - req[last][1]), req[last][0]);
        }
        if(dp[mask][last] != -1) return dp[mask][last];
        ll ans = 1e18;
        for(int i = 0; i < n; i++) {
            if((prevMask & (1 << i)) == 0) continue;
            ans = min(ans, max(abs(req[i][1] - req[last][1])  + fun(prevMask, i, start, req, dp), 1LL * req[last][0]));
        }
        return dp[mask][last] = ans;
    }
    long long elevatorRequests(int n, int start, vector<vector<int>>& req) {
        ll ans = 1e18;
        int sz = req.size();
        int mask = (1 << sz) - 1;
        vector<vector<ll>> dp(mask + 1, vector<ll> (sz, -1));
        for(int i = 0; i < sz; i++) {
            ans = min(ans, fun(mask, i, start, req, dp));
        }
        return ans;
    }
};