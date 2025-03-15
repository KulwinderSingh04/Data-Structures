class Solution {
public:
    bool fun(vector<int>& nums, int k, int mid) {
        int n = nums.size();
        int house = 0;
        int i = 0;
        while(i < n) {
            if(nums[i] <= mid) {
                house++;
                i += 2;
            }
            else i += 1;
        }
        return house >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i = 0; i < n; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        int ans = 0;
        int lo = mn;
        int hi = mx;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(fun(nums, k, mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};