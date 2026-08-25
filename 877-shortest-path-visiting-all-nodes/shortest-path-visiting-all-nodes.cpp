class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> mat(n, vector<int> (n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                mat[i][graph[i][j]] = 1;
            }
        }
        vector<vector<int>> dp((1 << n), vector<int> (n, 1e9));
        for(int i = 0; i < n; i++) {
            dp[1 << i][i] = 0;
        }
        for(int mask = 1; mask < (1 << n); mask++) {
            for(int last = 0; last < n; last++) {
                if(dp[mask][last] == 1e9) continue;
                if((mask & (1 << last)) == 0) continue;
                for(int node = 0; node < n; node++) {
                    int newMask = mask | (1 << node);
                    if(node == 3) {
                        cout << last << " " << mask << endl;
                    }
                    // if(mask == 7 && last == 0 && node == 3) {
                    //     cout << newMask << " " << dp[mask][last] << endl;
                    // }
                    if(mat[last][node]) {
                        // cout << last << "" << node << endl;
                        dp[newMask][node] = min(dp[newMask][node], 1 + dp[mask][last]);
                    }
                }
            }
        }
        for(int mask = 1; mask < (1 << n); mask++) {
            for(int last = 0; last < n; last++) {
                if(dp[mask][last] == 1e9) continue;
                if((mask & (1 << last)) == 0) continue;
                for(int node = 0; node < n; node++) {
                    int newMask = mask | (1 << node);
                    if(node == 3) {
                        cout << last << " " << mask << endl;
                    }
                    // if(mask == 7 && last == 0 && node == 3) {
                    //     cout << newMask << " " << dp[mask][last] << endl;
                    // }
                    if(mat[last][node]) {
                        // cout << last << "" << node << endl;
                        dp[newMask][node] = min(dp[newMask][node], 1 + dp[mask][last]);
                    }
                }
            }
        }
        for(int mask = 1; mask < (1 << n); mask++) {
            for(int last = 0; last < n; last++) {
                if(dp[mask][last] == 1e9) continue;
                if((mask & (1 << last)) == 0) continue;
                for(int node = 0; node < n; node++) {
                    int newMask = mask | (1 << node);
                    if(node == 3) {
                        cout << last << " " << mask << endl;
                    }
                    // if(mask == 7 && last == 0 && node == 3) {
                    //     cout << newMask << " " << dp[mask][last] << endl;
                    // }
                    if(mat[last][node]) {
                        // cout << last << "" << node << endl;
                        dp[newMask][node] = min(dp[newMask][node], 1 + dp[mask][last]);
                    }
                }
            }
        }
        for(int mask = 1; mask < (1 << n); mask++) {
            for(int last = 0; last < n; last++) {
                if(dp[mask][last] == 1e9) continue;
                if((mask & (1 << last)) == 0) continue;
                for(int node = 0; node < n; node++) {
                    int newMask = mask | (1 << node);
                    if(node == 3) {
                        cout << last << " " << mask << endl;
                    }
                    // if(mask == 7 && last == 0 && node == 3) {
                    //     cout << newMask << " " << dp[mask][last] << endl;
                    // }
                    if(mat[last][node]) {
                        // cout << last << "" << node << endl;
                        dp[newMask][node] = min(dp[newMask][node], 1 + dp[mask][last]);
                    }
                }
            }
        }
        for(int mask = 1; mask < (1 << n); mask++) {
            for(int last = 0; last < n; last++) {
                if(dp[mask][last] == 1e9) continue;
                if((mask & (1 << last)) == 0) continue;
                for(int node = 0; node < n; node++) {
                    int newMask = mask | (1 << node);
                    if(node == 3) {
                        cout << last << " " << mask << endl;
                    }
                    // if(mask == 7 && last == 0 && node == 3) {
                    //     cout << newMask << " " << dp[mask][last] << endl;
                    // }
                    if(mat[last][node]) {
                        // cout << last << "" << node << endl;
                        dp[newMask][node] = min(dp[newMask][node], 1 + dp[mask][last]);
                    }
                }
            }
        }
        for(int mask = 1; mask < (1 << n); mask++) {
            for(int last = 0; last < n; last++) {
                if(dp[mask][last] == 1e9) continue;
                if((mask & (1 << last)) == 0) continue;
                for(int node = 0; node < n; node++) {
                    int newMask = mask | (1 << node);
                    if(node == 3) {
                        cout << last << " " << mask << endl;
                    }
                    // if(mask == 7 && last == 0 && node == 3) {
                    //     cout << newMask << " " << dp[mask][last] << endl;
                    // }
                    if(mat[last][node]) {
                        // cout << last << "" << node << endl;
                        dp[newMask][node] = min(dp[newMask][node], 1 + dp[mask][last]);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(auto x : mat) {
            for(auto y : x) cout << y << " ";
            cout << endl;
        }
        for(auto x : dp[(1 << n) - 1]) ans = min(x, ans);
        return ans;
    }
};