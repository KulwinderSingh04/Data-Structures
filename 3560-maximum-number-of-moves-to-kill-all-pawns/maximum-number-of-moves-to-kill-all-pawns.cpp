class Solution {
public:
    typedef pair<pair<int, int>, int> pp;
    void bfs(int i, vector<vector<int>>& minSteps, vector<vector<int>>& pos) {
        int n = pos.size();
        vector<vector<int>> dir = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
        queue<pp> q;
        q.push({{pos[i][0], pos[i][1]}, 0});
        vector<vector<int>> v(50, vector<int> (50, -1));
        v[pos[i][0]][pos[i][1]] = 0;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int r = t.first.first;
            int c = t.first.second;
            int steps = t.second;
            for(int i = 0; i < 8; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= 50 || nc < 0 || nc >= 50 || v[nr][nc] != -1) continue;
                v[nr][nc] = steps + 1;
                q.push({{nr, nc}, steps + 1});
            }
        }
        for(int j = 0; j < pos.size(); j++) {
            int x = pos[j][0];
            int y = pos[j][1];
            minSteps[i][j] = v[x][y];
        }
    }
    int solve(int i, vector<vector<int>>& pos, bool alice, int mask, vector<vector<int>>& minSteps, vector<vector<int>>& dp) {
        int n = pos.size();
        if(mask == ((1 << n) - 1)) return 0;
        if(dp[i][mask] != -1) return dp[i][mask];
        int res;
        if(alice) res = 0;
        else res = 1e8;
        for(int j = 1; j < n; j++) {
            if((mask & (1 << j))) continue;
            if(alice) {
                res = max(res, minSteps[i][j] + solve(j, pos, !alice, mask | (1 << j), minSteps, dp));
            } else {
                res = min(res, minSteps[i][j] + solve(j, pos, !alice, mask | (1 << j), minSteps, dp));
            }
        }
        return dp[i][mask] = res;
    }
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.insert(positions.begin(), {kx, ky});
        int n = positions.size();
        vector<vector<int>> minSteps(n, vector<int> (n, -1));
        for(int i = 0; i < n; i++) {
            bfs(i, minSteps, positions);
        }
        vector<vector<int>> dp(n, vector<int> (1 << 16, -1));
        return solve(0, positions, true, 1, minSteps, dp);
    }
};