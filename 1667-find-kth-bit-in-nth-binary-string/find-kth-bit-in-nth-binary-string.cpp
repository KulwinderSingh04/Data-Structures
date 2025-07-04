class Solution {
public:
    int fun(int k) {
        if(k == 1) return 0;
        // cout << n << " " << k << endl;
        int t = k;
        while(t != 1) {
            if(t % 2) break;
            t /= 2;
        }
        if(t == 1) return '1';
        int n = 0;
        for(int i = 0;; i++) {
            n++;
            if(pow(2, n) >= k) break;
        } 
        cout << n << " " << k << endl;
        return !fun(pow(2, n) / 2 - (k - pow(2, n) / 2));
    }
    char findKthBit(int n, int k) {
        if(k == 1) return '0';
        int t = k;
        while(t != 1) {
            if(t % 2) break;
            t /= 2;
        }
        if(t == 1) return '1';
        return fun(k) + 48;
    }
};