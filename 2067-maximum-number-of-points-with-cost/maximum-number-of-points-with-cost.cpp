class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long> prev;
        for(auto x : points[0]) prev.push_back(x);
        for(int i = 1; i < n; i++) {
            vector<long long> left(m), right(m);
            for(int j = 0; j < m; j++) {
                if(j == 0) left[j] = prev[j];
                else left[j] = max(prev[j], left[j - 1] - 1);
            }
            for(int j = m - 1; j >= 0; j--) {
                if(j == m - 1) right[j] = prev[j];
                else right[j] = max(prev[j], right[j + 1] - 1);
            }
            for(int j = 0; j < m; j++) prev[j] = points[i][j] + max(left[j], right[j]);
        }
        long long mx = 0;
        for(auto x : prev) mx = max(mx, x);
        return mx;
    }
};