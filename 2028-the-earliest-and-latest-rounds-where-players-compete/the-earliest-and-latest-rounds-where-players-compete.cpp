class Solution {
public:
    vector<int> earliestAndLatest(int n, int left, int right) {
        if(left + right == n + 1) return {1, 1};
        if(left > n - right + 1) {
            int temp = n + 1 - left;
            left = n - right + 1;
            right = temp;
        }

        int mn = n;
        int mx = 0;
        int nextCount = (n + 1) / 2;
        if(right <= nextCount) {
            for(int surLeft = 0; surLeft < left; surLeft++) {
                for(int surMid = 0; surMid < right - left; surMid++) {
                    int nextLeft = surLeft + 1;
                    int nextRight =nextLeft + surMid + 1;
                    auto t = earliestAndLatest(nextCount, nextLeft, nextRight);
                    mn = min(mn, t[0] + 1);
                    mx = max(mx, t[1] + 1);
                }
            }
        } else {
            int fightsRight = n - right + 1;
            int countLeft = left - 1;
            int midCount = fightsRight - left - 1;
            int remMidCount = right - fightsRight - 1;
            for(int surLeft = 0; surLeft <= countLeft; surLeft++) {
                for(int surMid = 0; surMid <= midCount; surMid++) {
                    int nextLeft = surLeft + 1;
                    int nextRight = nextLeft + surMid + 1 + (remMidCount + 1) / 2;
                    auto t = earliestAndLatest(nextCount, nextLeft, nextRight);
                    mn = min(mn, t[0] + 1);
                    mx = max(mx, t[1] + 1);
                }
            }
        }
        return {mn, mx};
    }
};