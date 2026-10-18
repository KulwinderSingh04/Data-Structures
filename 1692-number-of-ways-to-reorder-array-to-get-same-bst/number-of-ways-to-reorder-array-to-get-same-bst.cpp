class Solution {
public:
    int MOD = 1e9 + 7;
    int power(int a, int b) {
        if(b == 0) return 1;
        int half = power(a, b / 2);
        half = (1LL * half * half % MOD);
        if(b % 2) return 1LL * a * half % MOD;
        return half; 
    }
    int ncr(int n, int r, vector<int>& fact) {
        return 1LL * fact[n] * power(fact[r], MOD - 2) % MOD * power(fact[n - r], MOD - 2) % MOD; 
    }
    int fun(vector<int>& nums, vector<int>& fact) {
        int n = nums.size();
        if(n == 1) return 1;
        int root = nums[0];
        vector<int> leftTree, rightTree;
        for(int i = 1; i < n; i++) {
            if(nums[i] < root) {
                leftTree.push_back(nums[i]);
            } else rightTree.push_back(nums[i]);
        }
        int cnt = leftTree.size();
        int x = 1;
        if(cnt != 0) x = fun(leftTree, fact);
        int y = 1;
        if(cnt != n - 1) y = fun(rightTree, fact);
        return 1LL * ncr(n - 1, cnt, fact) * x % MOD * y % MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<int> fact(n + 1);
        fact[0] = 1;
        for(int i = 1; i <= n; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;
        return (fun(nums, fact) - 1 + MOD) % MOD;
    }
};