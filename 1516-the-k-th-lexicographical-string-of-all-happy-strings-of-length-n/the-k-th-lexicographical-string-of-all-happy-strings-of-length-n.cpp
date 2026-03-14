class Solution {
public:
    string getHappyString(int n, int k) {
        string ans = "";
        if(3 * (1 << (n - 1)) < k) return "";
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                int div = k / (1 << (n - 1 - i)) - 1;
                if(k % (1 << (n - 1 - i)) == 0) ans += div + 97;
                else ans += div + 98;
                k = k % (1 << (n - 1 - i));
                if(k == 0) k = (1 << (n - 1 - i));
            } else {
                vector<int> v;
                if(ans.back() == 'a') v = {'b', 'c'};
                else if(ans.back() == 'b') v = {'a', 'c'};
                else v = {'a', 'b'};
                int div = k / (1 << (n - 1 - i)) - 1;
                if(k % (1 << (n - 1 - i)) == 0) ans += v[div];
                else ans += v[div + 1];
                k = k % (1 << (n - 1 - i));
                if(k == 0) k = (1 << (n - 1 - i));
            }
        }
        return ans;
    }
};