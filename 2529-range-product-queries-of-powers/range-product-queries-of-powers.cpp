class Solution {
public:
    int MOD = 1e9+7;
    void buildTree(int i, int l, int r, vector<long long>& segTree, vector<int>& powers) {
        if(l == r) {
            segTree[i] = powers[l];
            return;
        }
        if(l > r) return;
        int mid = l + (r - l) / 2;
        buildTree(2 * i + 1, l, mid, segTree, powers);
        buildTree(2 * i + 2, mid + 1, r, segTree, powers);
        segTree[i] = ((segTree[2 * i + 1] % MOD) * (segTree[2 * i + 2] % MOD)) % MOD;
    }

    int query(int i, int l, int r, int left, int right, vector<long long>& segTree) {
        if(right < l || left > r) return 1;
        if(left <= l && right >= r) return segTree[i];
        int mid = l + (r - l) / 2;
        long long a = 1, b = 1;
        a = query(2 * i + 1, l, mid, left, right, segTree);
        b = query(2 * i + 2, mid + 1, r, left, right, segTree);
        return (a % MOD * (b % MOD)) % MOD;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for(int i = 0; i < 32; i++) {
            if(n & (1 << i)) {
                powers.push_back(1 << i);
            }
        }
        int n1 = powers.size();
        vector<long long> segTree(4 * n1);
        vector<int> ans;
        buildTree(0, 0, n1 - 1, segTree, powers);
        for(auto x : queries) {
            ans.push_back(query(0, 0, n1 - 1, x[0], x[1], segTree));
        }
        return ans;
    }
};