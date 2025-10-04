class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(int i = 0; i < n - 1; i++) {
            dist[i][i + 1] = 1;
            dist[i + 1][i] = 1;
        }
        dist[x - 1][y - 1] = min(dist[x - 1][y - 1], 1);
        dist[y - 1][x - 1] = min(dist[y - 1][x - 1], 1);
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // cout << dist[i][j] << " ";
                if(i != j) {
                    if(dist[i][j] != INT_MAX) {
                        res[dist[i][j] - 1]++;
                    }
                }
            }
            // cout << endl;
        }
        // for(int i = n - 2; i >= 0; i--) {
        //     res[i] += res[i + 1];
        // }
        return res;
    }
};