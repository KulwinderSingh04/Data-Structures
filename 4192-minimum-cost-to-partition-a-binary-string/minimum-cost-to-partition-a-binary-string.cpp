class Solution {
public:
    long long fun(int l, int r, string& s, int& encCost, int& flatCost) {
        if(l > r) return 1e17;
        int sen = 0;
        for(int i = l; i <= r; i++) {
            sen += s[i] == '1';
        }
        long long cost = 0;
        if(sen == 0) cost = flatCost;
        else cost = 1LL * (r - l + 1) * sen * encCost;
        if((r - l + 1) % 2 == 0) {
            int mid = l + (r - l) / 2;
            cost = min(cost, fun(l, mid, s, encCost, flatCost) + fun(mid + 1, r, s, encCost, flatCost));
        }
        return cost;
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        return fun(0, n - 1, s, encCost, flatCost);
    }
};