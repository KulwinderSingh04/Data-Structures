bool cmp(vector<int>& a, vector<int>& b) {
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans = 0;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            // cout << points[i][0] << "," << points[i][1] << " ";
            int mx = INT_MIN;
            for(int j = i + 1; j < n; j++) {
                if(points[j][1] <= points[i][1] && points[j][1] > mx) {
                    ans++;
                    mx = max(mx, points[j][1]);
                }
            }
        }
        return ans;
    }
};