class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& con) {
        unordered_map<int, vector<long long>> mp;
        for(auto x : con) {
            mp[max(x[0], x[1])]. push_back(min(x[0], x[1]));
        }
        vector<long long> extra(n + 1);
        long long validSub = 0;
        long long addSub = 0;
        long long mx1 = 0, mx2 = 0;
        for(int i = 1; i <= n; i++) {
            for(auto x : mp[i]) {
                if(x >= mx1) {
                    mx2 = mx1;
                    mx1 = x;
                } else if(mx2 < x) mx2 = x; 
            }
            validSub += i - mx1;
            extra[mx1] += mx1 - mx2;
        }
        return validSub + *max_element(extra.begin(), extra.end());
    }
};