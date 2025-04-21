class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> v(n + 1);
        v[n] = upper;
        long long mx = upper, mn = v[n];
        for(int i = n - 1; i >= 0; i--) {
            v[i] = v[i + 1] - differences[i];
            mx = max(mx, v[i]);
            mn = min(mn, v[i]);
        }
        mn -= (mx - upper);
        return mn - lower < 0 ? 0 : mn - lower + 1;
    }
};