class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        while(numBottles != 0) {
            ans += numBottles;
            int extra = numBottles % numExchange;
            numBottles /= numExchange;
            if(numBottles == 0) break;
            numBottles += extra;
            ans -= extra;
            // numExchange++;
        }
        return ans;
    }
};