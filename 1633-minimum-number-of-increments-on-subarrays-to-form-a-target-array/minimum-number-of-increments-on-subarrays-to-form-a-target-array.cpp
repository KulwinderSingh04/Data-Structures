class Solution {
public:
    void buildTree(int i, int l, int r, vector<int>& target, vector<int>& segTree) {
        if(l == r) {
            segTree[i] = target[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2 * i + 1, l, mid, target, segTree);
        buildTree(2 * i + 2, mid + 1, r, target, segTree);

        segTree[i] = min(segTree[2 * i + 1], segTree[2 * i + 2]);

    }
    int query(int i, int l, int r, int left, int right, vector<int>& segTree) {
        if(right < l || r < left) return INT_MAX;
        if(l >= left && r <= right) {
            return segTree[i];
        }
        int mid = l + (r - l) / 2;
        int a = query(2 * i + 1, l, mid, left, right, segTree);
        int b = query(2 * i + 2, mid + 1, r, left, right, segTree);
        return min(a, b);

    }
    int fun(vector<int>& target, int lo, int hi, int prev, unordered_map<int, vector<int>>& mp, vector<int>& segTree) {
        if(lo > hi) return 0;
        int n = target.size();
        int ele = query(0, 0, n - 1, lo, hi, segTree);
        int ans = ele - prev;
        auto& vec = mp[ele];
        int l = lower_bound(vec.begin(), vec.end(), lo) - vec.begin();
        int r = upper_bound(vec.begin(), vec.end(), hi) - vec.begin();
        int prevIdx = lo - 1;
        for(int i = l; i < r; i++) {
            ans += fun(target, prevIdx + 1, vec[i] - 1, ele, mp, segTree);
            prevIdx = vec[i];
        }
        ans += fun(target, prevIdx + 1, hi, ele, mp, segTree);
        return ans;
    }
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        vector<int> segTree(4 * n, INT_MAX);
        buildTree(0, 0, n - 1, target, segTree);
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[target[i]].push_back(i);
        }
        return fun(target, 0, n - 1, 0, mp, segTree);
    }
};