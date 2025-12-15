class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0 || prices[i] == prices[i - 1] - 1) count++;
            else count = 1;
            ans += count;
        }
        return ans;
    }
};