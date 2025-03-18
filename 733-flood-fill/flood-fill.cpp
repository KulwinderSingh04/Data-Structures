class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    typedef pair<int, int> pp;
    void bfs(vector<vector<int>>& image, int r, int c, int color, int oc) {
        int n = image.size();
        int m = image[0].size();
        queue<pp> q;
        q.push({r, c});
        image[r][c] = color;
        // vector<vector<int>> vis(n, vector<int> (m));
        // vis[r][c] = 1;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for(int i = 0 ; i < 4; i++) {
                int nr = t.first + dir[i][0];
                int nc = t.second + dir[i][1];
              
                if(nr>=0 && nr<n && nc>=0 &&nc<m && image[nr][nc] == oc) {
                    q.push({nr, nc});
                    image[nr][nc] = color;
                }
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        int oc = image[sr][sc];
        bfs(image, sr, sc, color, oc);
        return image;
    }
};