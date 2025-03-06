class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> hash(n * n + 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                hash[grid[i][j]]++;
            }
        }
        int miss, twice;
        for(int i = 0; i < n * n + 1; i++) {
            if(hash[i] == 0) miss = i;
            if(hash[i] == 2) twice = i;
        }
        return {twice, miss};
    }
};