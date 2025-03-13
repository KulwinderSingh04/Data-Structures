class Solution {
public:
    bool fun(vector<int>& nums, vector<vector<int>>& q, int mid) {
        int n = nums.size();
        vector<int> diff(n);
        for(int i = 0; i <= mid; i++) {
            diff[q[i][0]] += q[i][2];
            if(q[i][1] + 1 < n) diff[q[i][1] + 1] += -q[i][2];
        }
        for(int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] - diff[i] > 0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int lo = 0;
        int hi = q.size() - 1;
        int ans = -1;
        bool flag = true;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                flag = false;
                break;
            }
        }
        if(flag) return 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(fun(nums, q, mid)) {
                cout << mid << endl;
                ans = mid + 1;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};