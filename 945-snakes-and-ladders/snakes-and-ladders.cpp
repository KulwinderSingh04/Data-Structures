class Solution {
public:
    // int fun(int goti, vector<vector<int>>& board, vector<int>& vis) {
    //     // if(goti > n * n) return 0;
    //     int n = board.size();
    //     if(goti >= n * n) return 0;
    //     // if(vis[goti] == 1) return 1e9;
    //     // vis[goti] = 1;
    //     if(board[r][c] == -1) {
    //         int mn = INT_MAX;
    //         for(int i = 1; i <= 6; i++) {
    //             mn = min(mn, 1 + fun(goti + i, board, vis));
    //         }
    //         return mn;
    //     } else {
    //         int newGoti = board[r][c];
    //         board[r][c] =
    //         int t = fun(newGoti, board, vis);
    //         board[r][c] = newGoti;
    //         return t;
    //     }
    // }
    vector<int> cord(int goti, int n) {
        int r = (goti - 1) / n;
        r = n - 1 - r;
        int c = (goti - 1) % n;
        if((n - 1 - r) % 2 == 1) c = n - 1 - c;
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> vis(n, vector<int> (n));
        queue<pair<int, int>> q;
        q.push({0, 1});
        vis[n - 1][0] = true;
        while(q.size()) {
            auto t = q.front();
            q.pop();

            int move = t.first;
            int goti = t.second;
            if(goti == n * n) return move;
            
            for(int i = 1; i < 7; i++) {
                int val = goti + i;
                if(val > n * n) continue;
                vector<int> v = cord(val, n);
                int r = v[0];
                int c = v[1];
                if(vis[r][c] == 1) continue;
                vis[r][c] = 1;
                if(board[r][c] == -1) {
                    q.push({move + 1, val});
                } else {
                    q.push({move + 1, board[r][c]});
                }
            }
            
        }
        return -1;
    }
};