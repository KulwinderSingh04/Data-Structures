class Solution {
public:
    bool dfs(int i, int col, vector<vector<int>>& adj, vector<int>& color) {
        color[i] = col;
        for(auto x : adj[i]) {
            if(color[x] == -1) {
                bool a = dfs(x, !col, adj, color);
                if(!a) return a;
            }
            else if(col == color[x]) return false;
        }
        return true;
    }
    bool check(int mid, vector<vector<int>>& dist) {
        int n =dist.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(dist[i][j] < mid) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++) {
            if(color[i] != -1) continue;
            if(dfs(i, 0, adj, color) == false) {
                return false;
            }
        }
        return true;
    }
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 2) return 0;
        vector<vector<int>> dist(n, vector<int> (n));
        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                dist[i][j] = dis;
                dist[j][i] = dis;
                mx = max(mx, dis);
            }
        }
        int ans = 0;
        int lo = 0;
        int hi = mx;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(check(mid, dist)) {
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;
    }
};