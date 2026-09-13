class Solution {
public:
    void update(int i, int l, int r, int idx, vector<int>& segTree) {
        if(l > r) return;
        if(l == r) {
            segTree[i]++;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) update(2 * i + 1, l, mid, idx, segTree);
        else update(2 * i + 2, mid + 1, r, idx, segTree);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
    int query(int i, int l, int r, int ql, int qr, vector<int>& segTree) {
        if(l > qr || r < ql) return 0;
        if(l >= ql && r <= qr) return segTree[i];
        int mid = l + (r - l) / 2;
        int ans = 0;
        ans += query(2 * i + 1, l, mid, ql, qr, segTree);
        ans += query(2 * i + 2, mid + 1, r, ql, qr, segTree);
        return ans;
    }
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        map<long long, int> mp;
        int n = nums.size();
        vector<long long> pref(n + 1), a;
        // pref[0] = nums[0];
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + nums[i - 1];
        }
        a = pref;
        sort(a.begin(), a.end());
        vector<int> segTree(4 * (n + 1));
        for(int i = 0; i < n + 1; i++) if(i == 0 || a[i] != a[i - 1]) mp[a[i]] = mp.size();
        long long ans = 0;
        for(int i = 0; i <= n; i++) {
            long long p = pref[i];
            auto itl = (mp.lower_bound(p - goal - k + 1));
            auto itr = mp.upper_bound(p - goal + k - 1);
            if(itl != mp.end() && itr != mp.begin()) {
                int l = itl -> second;
                int r = prev(itr) -> second;
                if(l <= r) ans += query(0, 0, n, l, r, segTree);
            }
            update(0, 0, n, mp[pref[i]], segTree);
        }
        return 1LL * n * (n + 1) / 2 - ans;
    }
};