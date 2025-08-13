class Solution {
public:
    vector<int> seive(int n) {
        vector<int> prime(n, 1);
        vector<int> ans;
        for(int i = 2; i < n; i++) {
            if(prime[i] == 1) {
                ans.push_back(i);
                for(int j = 2 * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        return ans;
    }
    int nonSpecialCount(int l, int r) {
        vector<int> prime = seive(sqrt(r) + 1);
        // return prime.size();
        int count = 0;
        for(int i = 0; i < prime.size(); i++) {
            long long a = 1LL * prime[i] * prime[i];
            if(a >= l && a <= r) count++;
            if(a > r) break;
        }
        return r - l + 1 - count;

    }
};