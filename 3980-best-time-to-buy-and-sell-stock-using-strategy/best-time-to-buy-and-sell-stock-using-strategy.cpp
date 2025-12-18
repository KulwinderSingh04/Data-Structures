class Solution {
public:
    long long maxProfit(vector<int>& price, vector<int>& strategy, int k) {
        int n = price.size();
        long long a = 0, ans = 0;
        int i = 0;
        int j = k - 1;
        vector<long long> prices(n);
        prices[0] = price[0];
        for(int l = 1; l < n; l++) prices[l] = prices[l - 1] + price[l];
        long long sum = 0;
        for(int l = 0; l < n; l++) {
            if(l < k - 1) sum += 1LL * strategy[l] * (prices[l] - (l != 0 ? prices[l - 1] : 0));
            ans += 1LL * strategy[l] * (prices[l] - (l != 0 ? prices[l - 1] : 0));
        }
        a = ans;
        long long diff = 0;
        while(j < n) {
            sum += strategy[j] * (prices[j] - (j != 0 ? prices[j - 1] : 0));
            int idx = i + k / 2 - 1;
            long long newSum = prices[j] - prices[idx];
            long long newDiff = newSum - sum;
            if(diff < newDiff) {
                diff = newDiff;
                ans = max(ans, a - sum + newSum);
            }
            sum -= 1LL * strategy[i] * (prices[i] - (i != 0 ? prices[i - 1] : 0));
            i++;
            j++;
        }
        return ans;
    }
};