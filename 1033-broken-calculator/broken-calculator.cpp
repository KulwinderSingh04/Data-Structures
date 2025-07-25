class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(target > startValue) {
            if(target % 2 == 0) target /= 2;
            else target++;
            ans++;
        }
        if(target < startValue) return ans + startValue - target;
        return ans;


    }
};