class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1 <= x2 && y1 >= y2) {
                    bool flag = true;
                    for(int k = 0; k < n; k++) {
                        if(k == i || k == j) continue;
                        if(points[k][0] >= x1 && points[k][0] <= x2 && points[k][1] >= y2 && points[k][1] <= y1) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};