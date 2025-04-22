class Solution {
public:
    void buildTree(vector<int>& segTree, vector<int>& nums, int i, int l, int r) {
        if(l == r) {
            segTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(segTree, nums, 2 * i + 1, l, mid);
        buildTree(segTree, nums, 2 * i + 2, mid + 1, r);
        int lMaxIdx = segTree[2 * i + 1];
        int rMaxIdx = segTree[2 * i + 2];
        if(nums[lMaxIdx] >= nums[rMaxIdx]) {
            segTree[i] = lMaxIdx;
        }
        else {
            segTree[i] = rMaxIdx;
        }
    }
    int query(vector<int>& segTree, vector<int>& nums, int left, int right, int i, int l, int r) {
        if(r < left || l > right) return -1;
        if(l >= left && r <= right) return segTree[i];

        int mid = l + (r - l) / 2;

        int leftMaxIdx = query(segTree, nums, left, right, 2 * i + 1, l, mid);
        int rightMaxIdx = query(segTree, nums, left, right, 2 * i + 2, mid + 1, r);
        if(leftMaxIdx == -1) return rightMaxIdx;
        if(rightMaxIdx == -1) return leftMaxIdx;

        if(nums[leftMaxIdx] >= nums[rightMaxIdx]) return leftMaxIdx;
        else return rightMaxIdx; 
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = heights.size();
        vector<int>segTree(4 * n);
        buildTree(segTree, heights, 0, 0, n - 1);
        int q = queries.size();
        for(int i = 0; i < q; i++) {
            int i1 = min(queries[i][0], queries[i][1]);
            int i2 = max(queries[i][0], queries[i][1]);

            if(heights[i1] < heights[i2] || i1 == i2) {
                ans.push_back(i2);
                continue;
            }
            int lo = max(queries[i][0], queries[i][1]) + 1;
            int hi = n - 1;
            int a = -1;
            while(lo <= hi) {

                int mid = lo + (hi - lo) / 2;
                int idx = query(segTree, heights, lo, mid, 0, 0, n - 1);
                if(heights[idx] > max(heights[queries[i][0]], heights[queries[i][1]])) {
                    a = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;

            }
            ans.push_back(a);
        }
        return ans;
    }
};