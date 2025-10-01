class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int r = numBottles;
        while(r) {
            ans += r;
            int extra = r % numExchange;
            r /= numExchange;
            if(r == 0) break;
            r += extra;
            ans -= extra;
        }
        return ans;
    }
};