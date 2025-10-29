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
        int ans = 0;
        for(int i = 0; i <= len; i++) ans |= (1 << len);
        return ans * 2 - 1;
    }
};