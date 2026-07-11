class Solution {
public:
    typedef pair<int, int> pp;
    int customUpperBound(vector<pp>& arr, int mx) {
        int n = arr.size();
        int lo = 0;
        int hi = n - 1;
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(arr[mid].first <= mx) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pp> arr;
        for(int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        vector<int> nodeToIdx(n);
        for(int i = 0; i < n; i++) {
            nodeToIdx[arr[i].second] = i;
        }
        int rows = n;
        int cols = log2(n) + 1;
        vector<vector<int>> up(rows, vector<int> (cols, -1));
        for(int node = 0; node < n; node++) {
            up[node][0] = customUpperBound(arr, arr[node].first + maxDiff);
        }
        for(int j = 1; j < cols; j++) {
            for(int node = 0; node < n; node++) {
                if(up[node][j - 1] != -1) {
                    up[node][j] = up[up[node][j - 1]][j - 1];
                }
            }
        }
        vector<int> ans;
        for(auto q : queries) {
            int a = nodeToIdx[q[0]];
            int b = nodeToIdx[q[1]];
            if(a > b) swap(a, b);
            if(a == b) {
                ans.push_back(0);
                continue;
            }
            int curr = a;
            int jumps = 0;
            for(int j = cols - 1; j >= 0; j--) {
                if(up[curr][j] < b) {
                    curr = up[curr][j];
                    jumps += (1 << j);
                }
            }
            if(up[curr][0] >= b) {
                ans.push_back(jumps + 1);
            } else ans.push_back(-1);
        }
        return ans;
    }
};