class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = max(low, 11); i <= min(high, 99); i++) {
            int a = i % 10;
            int b = i / 10;
            if(a == b) count++;
        }
        for(int i = max(low, 1000); i <= min(high, 9999); i++) {
            int a = i % 10;
            int b = (i / 10) % 10;
            int c = (i / 100) % 10;
            int d = (i / 1000) % 10;
            if(a + b == c + d) count++;
        }
        return count;
    }
};