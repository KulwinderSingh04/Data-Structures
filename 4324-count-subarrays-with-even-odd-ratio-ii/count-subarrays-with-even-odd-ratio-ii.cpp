class Solution {
public:
    int query(long long i, long long l, long long r, long long ql, long long qr, vector<long long>& segTree) {
        if(l > r) return 0;
        if(r < ql || l > qr) return 0;
        if(l >= ql && r <= qr) return segTree[i];
        int mid = l + (r - l) / 2;
        return query(2 * i + 1, l, mid, ql ,qr, segTree) + query(2 * i + 2, mid + 1, r, ql, qr, segTree);
    }
    void update(long long i, long long l, long long r, long long idx, vector<long long>& segTree) {
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
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        long long even = 0, odd = 0;
        vector<long long> v;
        v.push_back(0);
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2) odd++;
            else even++;
            v.push_back(odd * a - even * b);
        }
        map<long long, vector<long long>> mp;
        for(int i = 0; i < v.size(); i++) mp[v[i]].push_back(i);
        vector<long long> vec(n + 1);
        int val = 0;
        
        for(auto x : mp) {
            for(auto y : x.second) {
                vec[y] = val;
            }
            val++;
        }
        vector<long long> segTree(4 * val);
        update(0, 0, val - 1, vec[0], segTree); 
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            // if(vec[i] > 0) ans++;
            ans += query(0, 0, val - 1, 0, vec[i], segTree);
            update(0, 0, val - 1, vec[i], segTree);
        }
        // buildTree(0, 0, n - 1, v, segTree);
        return ans;
    }
};