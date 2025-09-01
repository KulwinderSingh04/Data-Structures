class Solution {
public:
    typedef pair<pair<int, int>, int> pp;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pp> q;
        q.push({{entrance[0], entrance[1]}, 0});
        maze[entrance[0]][entrance[1]] = '+';
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int r = t.first.first;
            int c = t.first.second;
            int step = t.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(maze[nr][nc] == '+') continue;
                if(nr == 0 || nr == n - 1 || nc == 0 || nc == m - 1) {
                    return step + 1;
                }
                maze[nr][nc] = '+';
                q.push({{nr, nc}, step + 1});
            }
        }
        return -1;
    }
};