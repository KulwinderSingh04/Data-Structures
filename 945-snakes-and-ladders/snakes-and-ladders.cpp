class Solution {
public:
    pair<int, int> cord(int t, int n) {
        int a = t % n ? t / n : t / n - 1;
        int r = n - 1 - a;
        int c = 0;
        if(a % 2 == 0) c = (t % n ? t % n - 1 : n - 1);
        else c = (t % n ? n - t % n : 0);
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<int> vis(n * n + 1);
        vis[1] = 1;
        while(q.size()) {
            auto t = q.front().first;
            int moves = q.front().second;
            q.pop();
            int r = cord(t, n).first;
            int c = cord(t, n).second;
            if(t == n * n) return moves;
            for(int i = t + 1; i < min(n *n + 1, t + 7); i++) {
                int nr = cord(i, n).first;
                int nc = cord(i, n).second;
                if(board[nr][nc] == -1) {
                    if(vis[i] == 0) {
                        vis[i] = 1;
                        q.push({i, moves + 1});
                    }
                } else {
                    // if(vis[i] == 0) {
                    //     vis[i] == 1;
                    // }
                    if(vis[board[nr][nc]] == 0) {
                        vis[board[nr][nc]] = 1;
                        q.push({board[nr][nc], moves + 1});
                    }
                }
            }
        }
        return -1;
    }
};