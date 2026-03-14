class Solution {
public:
    long long fun(int l, int r, vector<int>& v, int& encCost, int& flatCost) {
        if(l > r) return 1e17;
        int sen = v[r];
        if(l > 0) sen -= v[l - 1];
        long long cost = 0;
        if(sen == 0) cost = flatCost;
        else cost = 1LL * (r - l + 1) * sen * encCost;
        if((r - l + 1) % 2 == 0) {
            int mid = l + (r - l) / 2;
            cost = min(cost, fun(l, mid, v, encCost, flatCost) + fun(mid + 1, r, v, encCost, flatCost));
        }
        return cost;
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = s[i] == '1';
            if(i > 0) v[i] += v[i - 1];
        }
        return fun(0, n - 1, v, encCost, flatCost);
    }
};