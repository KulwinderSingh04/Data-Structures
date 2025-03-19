class Solution {
public:
    typedef pair<int, int> pp;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& board, int r, int c) {
        int n = board.size();
        int m = board[0].size();
        board[r][c] = 2;
        for(int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || board[nr][nc] != 1) continue;
            dfs(board, nr, nc);
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 1) {
                dfs(board, i, 0);
            }
            if(board[i][m - 1] == 1) {
                dfs(board, i, m - 1);
            }
        }
        for(int i = 0; i < m; i++) {
            if(board[0][i] == 1) {
                dfs(board, 0, i);
                
            }
            if(board[n - 1][i] == 1) {
                dfs(board, n - 1, i);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};