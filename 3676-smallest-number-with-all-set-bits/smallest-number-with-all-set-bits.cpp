class Solution {
public:
    int smallestNumber(int n) {
        int len = 0;
        for(int i = 31; i >= 0; i--) {
            if(n & (1 << i)) {
                len = i;
                break;
            }
        }
        return (1 << len + 1) - 1;
    }
};