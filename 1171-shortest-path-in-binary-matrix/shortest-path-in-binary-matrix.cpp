class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int ans = -1;
        int n = mat.size();
        queue<pair<int, pair<int, int>>> q;
        if(mat[0][0] == 0) {
            q.push({1, {0, 0}});
            mat[0][0] = 1;
        }
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int dis = t.first;
            int r = t.second.first;
            int c = t.second.second;
            if(r == n - 1 && c == n - 1) return dis;
            for(int i = 0; i < 8; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n || mat[nr][nc] == 1) continue;
                q.push({dis + 1,{nr, nc}});
                mat[nr][nc] = 1;
            }
        }
        return ans;
    }
};