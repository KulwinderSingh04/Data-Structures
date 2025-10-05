class Solution {
public:
    typedef pair<int, int> pp;
    void bfs(queue<pp>& q, vector<vector<int>>& mat, vector<vector<int>>& vis) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int r = t.first;
            int c = t.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] == 1 || mat[nr][nc] < mat[r][c]) continue;
                q.push({nr, nc});
                vis[nr][nc] = 1;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pp> q1, q2;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis1(n, vector<int> (m)), vis2(n, vector<int> (m));
        for(int i = 0; i < n; i++) {
            q1.push({i, 0});
            vis1[i][0] = 1;
            q2.push({i, m - 1});
            vis2[i][m - 1] = 1;
        }
        for(int j = 0; j < m; j++) {
            q1.push({0, j});
            vis1[0][j] = 1;
            q2.push({n - 1, j});
            vis2[n - 1][j] = 1;
        }
        bfs(q1, heights, vis1);
        bfs(q2, heights, vis2);
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis1[i][j] == 1 && vis2[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};