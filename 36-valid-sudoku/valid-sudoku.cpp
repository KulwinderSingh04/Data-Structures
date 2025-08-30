class Solution {
public:
    bool isSafe(int r, int c, vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(i != r && board[i][c] == board[r][c]) {
                // cout << i << " " << c << endl;
                return false;
            }
            if(i != c && board[r][i] == board[r][c]) {
                // cout << c << " " << i << endl;
                return false;
            }
        }
        int x = r / 3 * 3, y = c / 3 * 3;
        for(int i = x; i < x + 3; i++) {
            for(int j = y; j < y + 3; j++) {
                if(i == r && c == j) continue;
                if(board[r][c] == board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(!isSafe(i, j, board)) {
                    cout << i << " " << j << endl;
                    return false;
                }
            }
        }
        return true;
    }
};