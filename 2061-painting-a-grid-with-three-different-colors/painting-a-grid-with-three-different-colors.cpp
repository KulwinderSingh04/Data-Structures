class Solution {
public:
    int MOD = 1e9+7;
    void findStates(int m, string a, vector<string>& v) {
        if(m == 0) {
            v.push_back(a);
            return;
        }
        if(a == "") {
            findStates(m - 1, a + 'R', v);
            findStates(m - 1, a + 'G', v);
            findStates(m - 1, a + 'B', v);
        } else if(a.back() == 'R') {
            findStates(m - 1, a + 'G', v);
            findStates(m - 1, a + 'B', v);
        } else if(a.back() == 'G') {
            findStates(m - 1, a + 'R', v);
            findStates(m - 1, a + 'B', v);
        } else {
            findStates(m - 1, a + 'G', v);
            findStates(m - 1, a + 'R', v);
        }
    }
    int solve(int n, int idx, vector<string>& v, vector<vector<int>>& dp) {
        if(n == 0) return 1;
        if(dp[n][idx] != -1) return dp[n][idx];
        string prev = v[idx];
        int res = 0;
        for(int i = 0; i < v.size(); i++) {
            bool flag = true;
            for(int j = 0; j < v[i].size(); j++) {
                if(prev[j] == v[i][j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) res += solve(n - 1, i, v, dp);
            res %= MOD;
        }
        return dp[n][idx] = res;
    }
    int colorTheGrid(int m, int n) {
        vector<string> columnStates;
        findStates(m , "",  columnStates);
        int sz = columnStates.size();
        int res = 0;
        vector<vector<int>> dp(n + 1, vector<int> (sz + 1, -1));
        for(int i = 0; i < sz; i++) {
            res += solve(n - 1, i, columnStates, dp);
            res %= MOD;
        }
        return res % MOD;
    }
};