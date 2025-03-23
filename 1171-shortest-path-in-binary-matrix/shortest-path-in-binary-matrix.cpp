class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        queue<pp> q;
        q.push({1, {0, 0}});
        grid[0][0] = 1;
        int ans = -1;
        // vector<vector<int>> vis(n, vector<int> (n));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int r = t.second.first;
            int c = t.second.second;
            if(r == n - 1 && c == n - 1) {
                ans = t.first;
                break;
            }
            for(int i = 0; i < 8; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] == 1) continue;
                grid[nr][nc] = 1;
                q.push({t.first + 1, {nr, nc}});
            }
        }
        return ans;
    }
};