class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        queue<tuple<int, int, int, int>> q;
        int n = classroom.size();
        int m = classroom[0].size();
        vector<vector<int>> mp(n, vector<int> (m));
        int b = 0;
        vector<vector<vector<vector<bool>>>> vis(n, vector<vector<vector<bool>>> (m, vector<vector<bool>> (energy + 1, vector<bool> (1 << 10))));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(classroom[i][j] == 'S') {
                    q.push({i, j, energy, 0});
                    vis[i][j][energy][0] = 1;
                } else if(classroom[i][j] == 'L') {
                    mp[i][j] = b++;
                }
            }
        }
        int ans = 1e9;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int moves = 0;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();
                if(mask == ((1 << b) - 1)) return moves;
                if(e - 1 < 0) continue;
                for(int i = 0; i < 4; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    int newMask = mask;
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m || classroom[nr][nc] == 'X') continue;
                    if(classroom[nr][nc] == 'L') newMask = mask | (1 << mp[nr][nc]);
                    int ne = e - 1;
                    if(ne == -1) continue;  
                    if(classroom[nr][nc] == 'R') ne = energy;
                    if(vis[nr][nc][ne][newMask]) continue;
                    q.push({nr, nc, ne, newMask});
                    vis[nr][nc][ne][newMask] = 1;
                }
            }
            moves++;
        }
        return ans == 1e9 ? -1 : ans;
    }
};