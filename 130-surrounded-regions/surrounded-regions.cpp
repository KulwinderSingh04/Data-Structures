class Solution {
public:
    typedef pair<int, int> pp;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pp> q;
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'Y';
            }
            if(board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = 'Y';
            }
        }
        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O') {
                q.push({0, i});
                board[0][i] = 'Y';
            }
            if(board[n - 1][i] == 'O') {
                q.push({n - 1, i});
                board[n - 1][i] = 'Y';
            }
        }
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int r = t.first;
            int c = t.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m || board[nr][nc] != 'O') continue;
                q.push({nr, nc});
                board[nr][nc] = 'Y';
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'Y') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};