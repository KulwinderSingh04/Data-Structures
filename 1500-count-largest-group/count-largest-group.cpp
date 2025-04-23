class Solution {
public:
    int sumDigits(int x) {
        int a = 0;
        while(x) {
            a += x % 10;
            x /= 10;
        }
        return a;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        int count = 0, mx = 0;
        for(int i = 1; i < n + 1; i++) {
            int t = sumDigits(i);
            m[t]++;
            if(m[t] == mx) {
                count++;
            }
            else if(m[t] > mx) {
                mx = m[t];
                count = 1;
            }
        }
        return count;
    }
};