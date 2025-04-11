class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int ans = 0;
        int n = prices.size();
        for(int i = 0 ; i < n; i++) {
            if(prices[i] > mn) {
                ans += prices[i] - mn;
                mn = prices[i];
            }
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};