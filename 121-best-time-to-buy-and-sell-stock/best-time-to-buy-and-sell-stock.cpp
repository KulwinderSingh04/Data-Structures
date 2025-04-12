class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mn = prices[0];
        int n = prices.size();
        for(int i = 0; i < n; i++) {
            ans = max(ans, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};