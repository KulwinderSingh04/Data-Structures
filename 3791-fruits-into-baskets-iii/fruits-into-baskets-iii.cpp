class Solution {
public:
    void buildTree(int i, int l, int r, vector<int>& baskets, vector<int>& segTree) {
        int n = baskets.size();
        if(l == r) {
            segTree[i] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2 * i + 1, l, mid, baskets, segTree);
        buildTree(2 * i + 2, mid + 1, r, baskets, segTree);
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }
    void query(int i, int l, int r, int target, vector<int>& segTree, int& ans) {
        if(l == r) {
            if(segTree[i] >= target) {
                ans++;
                segTree[i] = -1;
            }
            return;
        }
        int mid = l + (r - l) / 2;
        if(segTree[2 * i + 1] >= target) {
            query(2 * i + 1, l, mid, target, segTree, ans);
        } else {
            query(2 * i + 2, mid + 1, r, target, segTree, ans);
        }
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segTree(4 * n);
        buildTree(0, 0, n - 1, baskets, segTree);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            query(0, 0, n - 1, fruits[i], segTree, ans);
        }
        return n - ans;
    }
};