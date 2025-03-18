class Solution {
public:
    typedef pair<pair<int, int>, int> pp;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int> (m, -1));
        queue<pp> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int r = t.first.first;
            int c = t.first.second;
            int dis = t.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m || ans[nr][nc] != -1) continue; 
                q.push({{nr, nc}, dis + 1});
                ans[nr][nc] = dis + 1;
            }
        }
        return ans;
    }
};