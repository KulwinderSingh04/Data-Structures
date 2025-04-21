class NumArray {
public:
    vector<int> segTree;
    int n;
    void buildTree(vector<int> & nums, int i, int l, int r) {
        if(l == r) {
            segTree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(nums, 2 * i + 1, l, mid);
        buildTree(nums, 2 * i + 2, mid + 1, r);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n);
        buildTree(nums, 0, 0, n - 1);
    }
    int query(int left, int right, int i, int l, int r) {
        if(r < left || l > right) return 0;
        if(l >= left && r <= right) return segTree[i];
        int mid = l + (r - l) / 2;  
        return query(left, right, 2 * i + 1, l, mid) + query(left, right, 2 * i + 2, mid + 1, r);
    }
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */