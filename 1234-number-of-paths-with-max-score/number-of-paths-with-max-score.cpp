class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> fun(int r, int c, vector<string>& board, vector<vector<vector<int>>>& dp) {
        if(r == 0 && c == 0) return {0, 1};
        long long score = INT_MIN, cnt = 0;
        vector<int> vec = {-1, -1};
        if(dp[r][c] != vec) return dp[r][c];
        if(r - 1 >= 0) {
            if(board[r - 1][c] != 'X') {
                vector<int> vec = fun(r - 1, c, board, dp);
                if(vec[0] + board[r][c] - '0' > score) {
                    score = vec[0] + board[r][c] - '0';
                    cnt = vec[1];
                } else if(vec[0] + board[r][c] - '0' == score) cnt += vec[1];
            }
        }
        if(c - 1 >= 0) {
            if(board[r][c -  1] != 'X') {
                vector<int> vec = fun(r, c - 1, board, dp);
                if(vec[0] + board[r][c] - '0' > score) {
                    score = vec[0] + board[r][c] - '0';
                    cnt = vec[1];
                } else if(vec[0] + board[r][c] - '0' == score) cnt += vec[1];
            }
        }
        if(r - 1 >= 0 && c - 1 >= 0) {
            if(board[r - 1][c - 1] != 'X') {
                vector<int> vec = fun(r - 1, c - 1, board, dp);
                if(vec[0] + board[r][c] - '0' > score) {
                    score = vec[0] + board[r][c] - '0';
                    cnt = vec[1];
                } else if(vec[0] + board[r][c] - '0' == score) cnt += vec[1];
            }
        }
        return dp[r][c] = {int(score % MOD),(int)(cnt % MOD)};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        board[0][0] = '0';
        board[n - 1][n - 1] = '0';
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, {-1, -1}));
        vector<int> ans = fun(n - 1, n - 1, board, dp);
        vector<int> vec = {0, 0};
        return ans[0] <= -1e7 ? vec : ans;
    }
};