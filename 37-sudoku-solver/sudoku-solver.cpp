class Solution {
public:
    bool isSafe(int r, int c, int num, vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(board[i][c] == num + 48) return false;
            if(board[r][i] == num + 48) return false;
        }
        int x = r / 3 * 3;
        int y = c / 3 * 3;
        for(int i = x; i < x + 3; i++) {
            for(int j = y; j < y + 3; j++) {
                if(board[i][j] == num + 48) return false;
            }
        }
        return true;
    }
    bool fun(int i, int j, vector<vector<char>>& board) {
        if(i == 9) return true;
        if(j == 9) return fun(i + 1, 0, board);
        if(board[i][j] != '.') return fun(i, j + 1, board);
        for(int num = 1; num <= 9; num++) {
            if(isSafe(i, j, num, board)) {
                board[i][j] = num + 48;
                bool a = fun(i, j + 1, board);
                if(a) return a; 
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        fun(0, 0, board);
    }
};