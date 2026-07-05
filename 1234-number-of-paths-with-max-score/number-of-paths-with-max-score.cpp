class Solution {
public:
    int fun1(int r, int c, vector<string>& board, vector<vector<int>>& dp) {
        if(r == 0 && c == 0) return 0;
        int ans = INT_MIN;
        if(dp[r][c] != -1) return dp[r][c];
        if(r - 1 >= 0) {
            if(board[r - 1][c] != 'X') {
                ans = board[r][c] - '0' + fun1(r - 1, c, board, dp);
            }
        }
        if(c - 1 >= 0) {
            if(board[r][c -  1] != 'X') {
                ans = max(ans, board[r][c] - '0' + fun1(r, c - 1, board, dp));
            }
        }
        if(r - 1 >= 0 && c - 1 >= 0) {
            if(board[r - 1][c - 1] != 'X') {
                ans = max(ans, board[r][c] - '0' + fun1(r - 1, c - 1, board, dp));
            }
        }
        return dp[r][c] = ans;
    }
    int MOD = 1e9 + 7;
    int fun2(int r, int c, int sum, vector<string>& board, vector<vector<vector<int>>>& dp) {
        if(r == 0 && c == 0) return sum == 0;
        if(sum < 0) return 0;
        long long ans = 0;
        if(dp[r][c][sum] != -1) return dp[r][c][sum];
        if(r - 1 >= 0) {
            if(board[r - 1][c] != 'X') {
                ans = fun2(r - 1, c, sum - (board[r][c] - '0'), board, dp);
                ans %= MOD;
            }
        }
        if(c - 1 >= 0) {
            if(board[r][c -  1] != 'X') {
                ans += fun2(r, c - 1,  sum - (board[r][c] - '0'), board, dp);
                ans %= MOD;
            }
        }
        if(r - 1 >= 0 && c - 1 >= 0) {
            if(board[r - 1][c - 1] != 'X') {
                ans += fun2(r - 1, c - 1,  sum - (board[r][c] - '0'), board, dp);
                ans %= MOD;
            }
        }
        return dp[r][c][sum] = ans;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        board[0][0] = '0';
        board[n - 1][n - 1] = '0';
        vector<vector<int>> dp1(n, vector<int> (n, -1));
        int mx = fun1(n - 1, n - 1, board, dp1);
        if(mx <= -1e7) return {0, 0};
        vector<vector<vector<int>>> dp2(n, vector<vector<int>> (n, vector<int> (mx + 1, -1)));
        return {mx, fun2(n - 1, n - 1, mx, board, dp2)};
    }
};