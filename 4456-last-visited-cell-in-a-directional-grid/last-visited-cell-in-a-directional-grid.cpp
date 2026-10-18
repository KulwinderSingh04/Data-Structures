class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m));
        int ar = 0, ac = 0;
        vis[0][0] = 1;
        while(ar >= 0 && ar < n && ac >= 0 && ac < m) {
            if(grid[ar][ac] == 'U') {
                if(ar - 1 < 0 || vis[ar - 1][ac] == 1) return {ar, ac};
                ar--;
            } else if(grid[ar][ac] == 'D') {
                if(ar + 1 >= n || vis[ar + 1][ac] == 1) return {ar, ac};
                ar++;
            } else if(grid[ar][ac] == 'L') {
                if(ac - 1 < 0 || vis[ar][ac - 1] == 1) return {ar, ac};
                ac--;
            } else {
                if(ac + 1 >= m || vis[ar][ac + 1] == 1) return {ar, ac};
                ac++;
            }
            vis[ar][ac] = 1;
        }
        return {ar, ac};
    }
};