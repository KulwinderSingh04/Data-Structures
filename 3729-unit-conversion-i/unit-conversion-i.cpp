class Solution {
public:
    int MOD = 1e9+7;
    vector<int> baseUnitConversions(vector<vector<int>>& con) {
        int n = con.size();
        // sort(con.begin(), con.end());
        vector<int> v(n + 1);
        v[0] = 1;
        for(int i = 0; i < n; i++) {
            v[con[i][1]] = (1LL * v[con[i][0]] * con[i][2]) % MOD;
        }
        return v;
    }
};