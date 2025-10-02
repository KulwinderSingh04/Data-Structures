class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int empty = 0, full = numBottles;
        while(full) {
            ans += full;
            empty += full;
            full = 0;
            if(empty >= numExchange) {
                empty -= numExchange;
                full++;
                numExchange++;
            } else break;
        }
        return ans;
    }
};