class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int x = (n + 1) / 2 % 2;
        vector<int> perm(n);
        int y = 0;
        for(int i = 1; i < n - 1; i += 2) {
            y ^= encoded[i];
        }
        perm[0] = x ^ y;
        for(int i = 1; i < n; i++) {
            perm[i] = perm[i - 1] ^ encoded[i - 1];
        }
        return perm;
    }
};