class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        while(n > 1) {
            int highFactor = 1;
            for(int i = n / 2; i > 0; i--) {
                if(n % i == 0) {
                    highFactor = i;
                    break;
                }
            }
            ans += n / highFactor;
            n = highFactor;
        }
        return ans;
    }
};