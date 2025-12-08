class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int k = sqrt(i * i + j * j);
                if(k * k == i * i + j * j && k <= n) ans++;
            }
        }
        return 2 * ans;
    }
};