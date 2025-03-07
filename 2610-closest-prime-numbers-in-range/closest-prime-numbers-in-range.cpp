class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(left <= 2 && right >= 3) return {2, 3};
        vector<int> v(right + 1, 1);
        v[1] = 0;
        for(int i = 2; i <= right; i++) {
            long long x = 1LL * i * i;
            while(x < right + 1) {
                v[x] = 0;
                x += i;
            }
        }
        int f = -1;
        int s = -1;
        int mx = INT_MAX;
        int l1 = -1, l2 = -1;
        for(int i = left; i <= right; i++) {
            if(v[i] == 1) {
                f = s;
                s = i;
                if(mx > s - f && f != -1) {
                    l1 = f;
                    l2 = s;
                    mx = s - f;
                    if(mx <= 2) return {l1, l2};
                }
            }
        }
        return {l1, l2};
    }
};