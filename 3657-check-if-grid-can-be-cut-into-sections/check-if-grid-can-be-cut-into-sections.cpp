class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hr, vr;
        int t = rectangles.size();
        for(int i = 0; i < t; i++) {
            hr.push_back({rectangles[i][0], rectangles[i][2]});
            vr.push_back({rectangles[i][1], rectangles[i][3]});
        }
        sort(vr.begin(), vr.end());
        sort(hr.begin(), hr.end());
        int h = 0, v = 0;
        int he = hr[0][1], ve = vr[0][1];
        for(int i = 1; i < t; i++) {
            if(hr[i][0] >= he) {
                he = hr[i][1];
                v++;
            }
            else he = max(he, hr[i][1]);
            if(vr[i][0] >= ve) {
                ve = vr[i][1];
                h++;
            }
            else ve = max(ve, vr[i][1]);
        }
        if(h >= 2 || v >= 2) return true;
        return false;
    }
};