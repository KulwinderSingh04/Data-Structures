class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ele1 = 0, ele2 = 0;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++) {
            if(c1 == 0) {
                ele1 = tops[i];
                c1 = 0;
            }
            if(ele1 != tops[i]) c1--;
            else c1++;
            
            if(c2 == 0) {
                ele2 = bottoms[i];
                c2 = 0;
            }
            if(ele2 != bottoms[i]) c2--;
            else c2++;
        }
        int ans = INT_MAX, count = 0;
        for(int i = 0; i < n; i++) {
            if(tops[i] != ele1) {
                if(bottoms[i] != ele1) {
                    count = INT_MAX;
                    break;
                } else count++;
            }
        }
        ans = count;
        count = 0;
        for(int i = 0;i < n; i++) {
            if(bottoms[i] != ele2) {
                if(tops[i] != ele2) {
                    count = INT_MAX;
                    break;
                } else count++;
            }
        }
        ans = min(ans, count);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};