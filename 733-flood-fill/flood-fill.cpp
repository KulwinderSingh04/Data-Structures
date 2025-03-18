class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int oc) {
        image[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++) {
            int nr = sr + dir[i][0];
            int nc = sc + dir[i][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || image[nr][nc] != oc) continue;
            dfs(image, nr, nc, color, oc);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        int oc = image[sr][sc];
        dfs(image, sr, sc, color, oc);
        return image;
    }
};