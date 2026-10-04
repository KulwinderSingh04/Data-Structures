class Solution {
public:
    int fun(int curr, int prev) {
        return min(abs(curr - prev), 10 - abs(curr - prev));
    }
    int minRotations(int n, string s) {
        vector<int> suff(n);
        int ans = 0, a = 0;
        int prev = 0;
        for(int i = n - 1; i >= 0; i--) {
            int curr = s[i] - '0';
            // int a = curr, b = prev;
            // if(a > b) swap(a, b);
            // cout << abs(curr - prev) <<endl;
            // cout<< min(, 9 - prev + curr + 1) << endl;
            suff[i] = fun(curr, prev);
            a += suff[i];
            prev = curr;
        }
        for(int i = n - 2; i >= 0; i--) suff[i] += suff[i + 1];
        ans = a;
        int p = 0;
        // cout << a << endl;
        // a -= suff[n - 1];
        int v = 0;
        for(int i = 0; i < n - 1; i++) {
            int curr = s[i] - '0';
            v += fun(curr, p);
            
            ans=  min(v + suff[i + 1] - suff[n - 1] + fun(s[n - 1] - '0', curr) , ans);
            p = curr;
        }
        return ans;
    }
};