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
        if(qr < l || ql > r) return 0;
        if(ql <= l && qr >= r) return segTree[i];
        int mid = l + (r - l) / 2;
        int ans = query(2 * i + 1, l, mid, ql, qr, segTree);
        ans += query(2 * i + 2, mid + 1, r, ql, qr, segTree);
        return ans;
    }
    vector<int> resultArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        mp[vec[0]] = 0;
        int val = 1;
        int n = vec.size();
        for(int i = 1; i < n; i++) {
            if(vec[i] != vec[i - 1]) {
                mp[vec[i]] = val++;
            }
        }
        vector<int> segTree1(4 * n);
        vector<int> segTree2(4 * n);
        update(0, 0, n - 1, mp[nums[0]], segTree1);
        update(0, 0, n - 1, mp[nums[1]], segTree2);
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i = 2; i < n; i++) {
            int q1 = query(0, 0, n - 1, mp[nums[i]] + 1, val - 1, segTree1);
            int q2 = query(0, 0, n - 1, mp[nums[i]] + 1, val - 1, segTree2);
            if(q1 > q2) {
                arr1.push_back(nums[i]);
                update(0, 0, n - 1, mp[nums[i]], segTree1);
            } else if(q1 < q2) {
                arr2.push_back(nums[i]);
                update(0, 0, n - 1, mp[nums[i]], segTree2);
            } else {
                if(arr1.size() <= arr2.size()) {
                    arr1.push_back(nums[i]);
                    update(0, 0, n - 1, mp[nums[i]], segTree1);
                }
                else {
                    arr2.push_back(nums[i]);
                    update(0, 0, n - 1, mp[nums[i]], segTree2);
                }
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};