class Solution {
public:
    bool fun(int n, int alice, vector<int>& v, vector<vector<int>>& dp) {
        if(n == 0) return alice == 1;
        if(dp[n][alice] != -1) return dp[n][alice];
        for(int i = 0; i < v.size(); i++) {
            if(v[i] <= n) {
                bool a = fun(n - v[i], !alice, v, dp);
                if(alice == 0) {
                    if(a) return dp[n][alice] = a;
                } else {
                    if(a == false) return dp[n][alice] = a;
                }
            } else break;
        }
        if(alice == 0) return dp[n][alice] = false;
        else return dp[n][alice] = true;
    }
    bool winnerSquareGame(int n) {
        vector<int> v;
        int num = 1;
        while(num * num <= 1e5) {
            v.push_back(num * num);
            num++;
        }
        // cout << v.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        return fun(n, 0, v, dp);
    }
};