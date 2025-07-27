class Solution {
public:
    int fun(int i, int l1, vector<int>& rods, unordered_map<string, int>& dp) {
        int n = rods.size();
        if(i == n) {
            if(l1 == 0) return 0;
            return INT_MIN;
        }
        string str = to_string(i) + "_" + to_string(l1);
        if(dp.find(str) != dp.end()) return dp[str];
        int a = rods[i] + fun(i + 1, l1 + rods[i], rods, dp);
        int b = fun(i + 1, l1 - rods[i], rods, dp);
        int c = fun(i + 1, l1, rods, dp);
        return dp[str] = max(a, max(b, c));
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        unordered_map<string, int> dp;
        return fun(0, 0, rods, dp);
    }
};