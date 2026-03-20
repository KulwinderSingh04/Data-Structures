class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int> (m - k + 1));
        for(int l1 = 0; l1 < n - k + 1; l1++) {
            for(int l2 = 0; l2 < m - k + 1; l2++) {
                vector<int> v;
                for(int i = l1; i < l1 + k; i++) {
                    for(int j = l2; j < l2 + k; j++) {
                        v.push_back(grid[i][j]);
                    }
                    // cout << v.back() << " ";
                }
                
                sort(v.begin(), v.end());
                int mn = INT_MAX;
                // cout << endl << v[0] << " ";
                for(int i = 1; i < v.size(); i++) {
                    // cout << v[i] << " ";
                    if(v[i] != v[i - 1]) mn = min( mn, v[i] - v[i - 1]);
                }
                if(mn == INT_MAX) mn = 0;
                ans[l1][l2] = mn;
            }
        }
        return ans;
    }
};