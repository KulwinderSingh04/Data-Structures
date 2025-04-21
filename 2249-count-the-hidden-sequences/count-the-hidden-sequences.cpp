class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long a = 0, b = 0;
        b = upper;
        long long mx = upper, mn = b;
        for(int i = n - 1; i >= 0; i--) {
            a = b - differences[i];
            mx = max(mx, a);
            mn = min(mn, a);
            b = a; 
        }
        mn -= (mx - upper);
        return mn - lower < 0 ? 0 : mn - lower + 1;
    }
};