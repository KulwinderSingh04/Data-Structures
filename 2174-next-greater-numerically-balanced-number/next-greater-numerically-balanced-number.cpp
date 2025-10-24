class Solution {
public:
    bool fun(int n) {
        vector<int> m(10);
        while(n) {
            m[n % 10]++;
            n /= 10;
        }
        for(int i = 0; i < 10; i++) if(m[i] != i && m[i] != 0) return false;
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i = n + 1; i < 1e7; i++) {
            if(fun(i)) return i;
        }
        return -1;
    }
};