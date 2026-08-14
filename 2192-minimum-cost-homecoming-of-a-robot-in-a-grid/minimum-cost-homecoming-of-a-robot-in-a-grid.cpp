class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int n = rowCosts.size();
        int m = colCosts.size();
        int startx = startPos[0];
        int starty = startPos[1];
        int endx = homePos[0];
        int endy = homePos[1];
        int ans = 0;
        if(startx < endx) {
            for(int i = startx + 1; i <= endx; i++) {
                ans += rowCosts[i];
            }
        } else {
            for(int i = startx - 1; i >= endx; i--) {
                ans += rowCosts[i];
            }
        }
        if(starty < endy) {
            for(int i = starty + 1; i <= endy; i++) {
                ans += colCosts[i];
            }
        } else {
            for(int i = starty - 1; i >= endy; i--) {
                ans += colCosts[i];
            }
        }
        return ans;
    }
};