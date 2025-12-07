class Solution {
public:
    vector<long long> segTree;
    void update(int idx, int l, int r, int pos, int val) {
        if(l == r) {
            segTree[idx] += val;
            return;
        }
        
        long long mid = l + (r - l) / 2;
        if(pos <= mid) {
            update(2 * idx + 1, l, mid, pos, val);
        } else {
            update(2 * idx + 2, mid + 1, r, pos, val);
        }
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if(l > qr || r < ql) return 0;
        if(l >= ql && r <= qr) return segTree[idx];
        long long mid = l + (r - l) / 2;
        long long leftAns = query(2 * idx + 1, l, mid, ql, qr);
        long long rightAns = query(2 * idx + 2, mid + 1, r, ql, qr);
        return rightAns + leftAns;
    }
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();
        segTree.resize(4 * n, 0);
        set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int idx = 1;
        for(auto x : st) {
            mp[x] = idx++;
        }
        for(auto& x : nums) {
            x = mp[x];
        }
        // for(auto x : nums)
        long long a = 0;
        for(int i = 0; i < k; i++) {
            a += query(0, 1, n, nums[i] + 1, n);
            update(0, 1, n, nums[i], 1);
        }
        long long ans = a;
        // cout << a << " ";
        for(int i = k; i < n; i++) {
            a -= query(0, 1, n, 1, nums[i - k] - 1);
            update(0, 1, n, nums[i - k], -1);
            a += query(0, 1, n, nums[i] + 1, n);
            update(0, 1, n, nums[i], 1);
            ans = min(ans, a);
            // cout << a << " ";
        }
        return ans;

    }
};