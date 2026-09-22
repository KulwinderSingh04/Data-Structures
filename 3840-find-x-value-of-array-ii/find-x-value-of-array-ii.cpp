class Node {
public:
    long long prod;
    int count[5];

    Node() {
        prod = 1;
        memset(count, 0, sizeof(count));
    }
};
class Solution {
public:
    Node makeLeafNode(int val, int k) {
        Node a;
        a.count[val % k]++;
        a.prod = val % k;
        return a;
    }
    Node mergeNode(Node& a, Node& b, int k) {
        Node c;
        c.prod = a.prod * b.prod % k;
        for(int i = 0; i < k; i++) {
            c.count[i] = a.count[i];
        }
        for(int i = 0; i < k; i++) {
            int rem = a.prod * i % k;
            c.count[rem] += b.count[i];
        }
        return c;
    }
    void buildTree(int i, int l, int r, int k, vector<int>& nums, vector<Node>& segTree) {
        if(l == r) {
            segTree[i] = makeLeafNode(nums[l], k);
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2 * i + 1, l, mid, k, nums, segTree);
        buildTree(2 * i + 2, mid + 1, r, k, nums, segTree);
        segTree[i] = mergeNode(segTree[2 * i + 1], segTree[2 * i + 2], k);
    }
    void update(int i, int l, int r, int idx, int val, int k, vector<int>& nums, vector<Node>& segTree) {
        if(l == r) {
            segTree[i].prod = val % k;
            for(int j = 0; j < k; j++) {
                segTree[i].count[j] = 0;
            }
            segTree[i].count[val % k] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) update(2 * i + 1, l, mid, idx, val, k, nums, segTree);
        else update(2 * i + 2, mid + 1, r, idx, val, k, nums, segTree);
        segTree[i] = mergeNode(segTree[2 * i + 1], segTree[2 * i + 2], k);
    }
    Node query(int i, int l, int r, int ql, int qr, int k, vector<int>& nums, vector<Node>& segTree) {
        if(l >= ql && r <= qr) return segTree[i];
        if(l > qr || r < ql) return Node();
        int mid = l + (r - l) / 2;
        if(qr <= mid) return query(2 * i + 1, l, mid, ql, qr, k, nums, segTree);
        else if(ql > mid) return query(2 * i + 2, mid + 1, r, ql, qr, k, nums, segTree);
        else {
            Node a = query(2 * i + 1, l, mid, ql, qr, k, nums, segTree);
            Node b = query(2 * i + 2, mid + 1, r, ql, qr, k, nums, segTree);
            return mergeNode(a, b, k);
        }
        // segTree[i] = mergeNode(segTree[2 * i + 1], segTree[2 * i + 2], k);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<Node> segTree(4 * n, Node());
        buildTree(0, 0, n - 1, k, nums, segTree);
        vector<int> ans;
        for(auto q : queries) {
            int ind = q[0];
            int val = q[1];
            update(0, 0, n - 1, ind, val, k, nums, segTree);
            Node res = query(0, 0, n - 1, q[2], n - 1, k, nums, segTree);
            ans.push_back(res.count[q[3]]);
        }
        return ans;
    }
};