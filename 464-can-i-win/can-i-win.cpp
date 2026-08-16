class Solution {
public:
    bool fun(int mask, int turn, int mx, int tot, vector<int>& dp) {
        if(tot <= 0) return turn;
        if(dp[mask] != -1) return dp[mask];
        for(int i = 1; i <= mx; i++) {
            if(mask & (1 << i)) continue;
            if(turn == 0) {
                if(fun(mask | (1 << i), !turn, mx, tot - i, dp)) return true;
            } else {
                if(!fun(mask | (1 << i), !turn, mx, tot - i, dp)) return !true;
            }
        }
        return dp[mask] = turn;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        if(desiredTotal == 0) return true;
        vector<int> dp((1 << (maxChoosableInteger + 1)), -1);
        return fun(0, 0, maxChoosableInteger, desiredTotal, dp);
    }
};