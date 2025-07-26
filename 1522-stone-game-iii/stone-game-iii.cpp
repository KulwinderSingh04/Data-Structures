class Solution {
public:
    int fun(int i,  vector<int>& stone, vector<int>& dp) {
        int n = stone.size();
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i]; 
        int sum = 0;
        int p = INT_MIN;
        for(int j = i; j < min(n, i + 3); j++) {
            sum += stone[j];
            p = max(p, sum - fun(j + 1, stone, dp));
        }
        return dp[i] = p;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1);
        int t = fun(0, stoneValue, dp);
        if(t > 0) return "Alice";
        else if(t == 0) return "Tie";
        return "Bob";
    }
};