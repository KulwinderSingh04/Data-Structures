class Solution {
public:
    int minAllOneMultiple(int k) {
        long long num = 1;
        if(k % 2 == 0 || k % 5 == 0) return -1;
        int count = 1;
        while(num % k != 0) {
            num = (num * 10 + 1) % k;
            count++;
        }
        return count;
    }
};