class Solution {
public:
    char fun(long long k, vector<int>& op) {
        if(k == 1) return 'a';
        long long len = 1;
        long long newk, opType;
        int n = op.size();
        for(int i = 0; i < n; i++) {
            len *= 2;
            if(len >= k) {
                newk = k - len / 2;
                opType = op[i];
                break;
            }
        }
        char ch = fun(newk, op);
        if(opType == 0) return ch;
        return ch == 'z' ? 'a' : 1 + ch;
    }
    char kthCharacter(long long k, vector<int>& operations) {
        return fun(k, operations);
    }
};