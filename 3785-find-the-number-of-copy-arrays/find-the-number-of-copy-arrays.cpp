class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        vector<int> pre(n);
        pre[0] = 0;
        for(int i = 1; i < n; i++) {
            pre[i] += pre[i - 1] + (original[i] - original[i - 1]);
        }
        int mini = bounds[0][0];
        int maxi = bounds[0][1];
        for(int i = 0; i < n; i++) {
            mini = max(mini, bounds[i][0] - pre[i]);
            maxi = min(maxi, bounds[i][1] - pre[i]);
        }
        if(maxi - mini + 1 < 0) return 0;
        return maxi - mini + 1;
    }
};