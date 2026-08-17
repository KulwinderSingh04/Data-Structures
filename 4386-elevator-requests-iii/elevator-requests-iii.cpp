class Solution {
public:
    typedef long long ll;
    ll fun(ll mask, ll last, int start, vector<vector<int>>& req, vector<vector<ll>>& dp) {
        ll prevMask = mask ^ (1 << last);
        if(prevMask == 0) {
            return dp[mask][last] = max(1LL * abs(start - req[last][1]), 1LL * req[last][0]);
        }
        if(dp[mask][last] != -1) return dp[mask][last];
        ll ans = 1e18;
        for(int i = 0; i < req.size(); i++) {
            if((prevMask & (1 << i)) == 0) continue;
            ll prevTime = fun(prevMask, i, start, req, dp);
            ll curr = max(prevTime + abs(req[last][1] - req[i][1]), 1LL * req[last][0]);
            ans = min(ans, curr);
        }
        return dp[mask][last] = ans;
    }
    long long elevatorRequests(int n, int start, vector<vector<int>>& req) {
        int m = req.size();
        ll full = (1 << m) - 1;
        vector<vector<ll>> dp((1 << m), vector<ll> (m, -1));
        ll res = 1e18;
        for(int i = 0; i < req.size(); i++) {
            res = min(res, fun(full, i, start, req, dp));
        }
        return res;
    }
};