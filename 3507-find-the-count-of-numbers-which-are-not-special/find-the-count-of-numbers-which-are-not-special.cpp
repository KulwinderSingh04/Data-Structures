class Solution {
public:
    vector<int> seive() {
        vector<int> prime(1e5, 1);
        vector<int> ans;
        for(int i = 2; i < 1e5; i++) {
            if(prime[i] == 1) {
                ans.push_back(i);
                for(int j = 2 * i; j < 1e5; j += i) {
                    prime[j] = 0;
                }
            }
        }
        return ans;
    }
    int nonSpecialCount(int l, int r) {
        vector<int> prime = seive();
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