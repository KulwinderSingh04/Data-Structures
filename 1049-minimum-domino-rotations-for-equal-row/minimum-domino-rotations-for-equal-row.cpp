class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        map<int, int> m1, m2;
        int ele1 = 0, ele2 = 0;;
        for(int i = 0; i < n; i++) {
            m1[tops[i]]++;
            if(m1[tops[i]] >= n / 2) ele1 = tops[i];

            m2[bottoms[i]]++;
            if(m2[bottoms[i]] >= n / 2) ele2 = bottoms[i];

        }
        cout << ele1 << " " << ele2 << endl;
        int ans = -1, count = 0;
        for(int i = 0; i < n; i++) {
            if(tops[i] != ele1) {
                if(bottoms[i] != ele1) {
                    count = -1;
                    break;
                } else count++;
            }
        }
        ans = count;
        count = 0;
        for(int i = 0;i < n; i++) {
            if(bottoms[i] != ele2) {
                if(tops[i] != ele2) {
                    count = -1;
                    break;
                } else count++;
            }
        }
        if(ans == -1) return count; 
        return min(ans, count);
    }
};