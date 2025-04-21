class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> v(n + 1);
        v[n] = upper;
        long long mx = upper;
        for(int i = n - 1; i >= 0; i--) {
            v[i] = v[i + 1] - differences[i];
            mx = max(mx, v[i]);
        }
        mx = mx - upper;
        long long mn = INT_MAX;
        for(int i = 0; i < v.size(); i++) {
            v[i] -= mx;
            mn = min(mn, v[i]);
        }
        return mn - lower < 0 ? 0 : mn - lower + 1;
        // int ans = ceil(v, lower, upper) - floor(v, lower, upper);
        // return ans < 0 ? 0 : ans + 1;
    }
};