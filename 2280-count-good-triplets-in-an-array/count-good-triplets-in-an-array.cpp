class Solution {
public:
    void segUpdate(vector<long long>& segTree, int idx, int i, int l, int r) {
        if(l == r) {
            segTree[i] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) {
            segUpdate(segTree, idx, 2 * i + 1, l, mid);
        }
        else {
            segUpdate(segTree, idx, 2 * i + 2, mid + 1, r);
        }
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
    
    long long query(vector<long long>& segTree, int left, int right, int i, int l, int r) {
        if(r < left || l > right) return 0;
        if(l >= left && r <= right) return segTree[i];
        int mid = l + ( r - l) / 2;
        return query(segTree, left, right, 2 * i + 1, l, mid) + query(segTree, left, right, 2 * i + 2, mid + 1, r);
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        int n = nums2.size();
        for(int i = 0; i < n; i++) m[nums2[i]] = i;
        vector<long long> segTree(4 * n);
        long long res = 0;
        segUpdate(segTree, m[nums1[0]], 0, 0, n - 1);
        for(int i = 1; i < n; i++) {
            int idx = m[nums1[i]];
            long long leftCommonCount = query(segTree, 0, idx - 1, 0, 0, n - 1);
            long long leftUncommonCount = i - leftCommonCount;
            long long eleAfterIdxNums2 = n - 1 - idx;
            long long rightCommonCount = eleAfterIdxNums2 - leftUncommonCount;
            res += leftCommonCount * rightCommonCount;
            
            segUpdate(segTree, idx, 0, 0, n - 1);
        }
        return res;
    }
};