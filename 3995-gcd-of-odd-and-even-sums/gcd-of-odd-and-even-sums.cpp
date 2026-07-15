class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for(int i = 1; i < 2* n; i+=2) {
            odd += i;
            even += i + 1;
        }
        return __gcd(odd, even);
    }
};