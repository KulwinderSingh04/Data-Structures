class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> v(n);
        v[0] = 1;
        int mn = INT_MAX;
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                v[i] = v[i - 1] + 1;
            }
            else {
                v[i] = 1;
            }
        }
        vector<int> v2(n, 1);
        v[n - 1] = max(v[n - 1], v2[n - 1]);
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                v2[i] = v2[i + 1] + 1;
            }
            else {
                v2[i] = 1;
            }
            v[i] = max(v[i], v2[i]);
            
            mn = min(mn, v[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(mn < 1) v[i] += 1 - mn;
            ans += v[i];
        }
        return ans;
    }
};