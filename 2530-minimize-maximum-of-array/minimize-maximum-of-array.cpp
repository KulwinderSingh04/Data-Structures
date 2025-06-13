class Solution {
public:
    bool fun(int mid, vector<int>& v) {
        int n = v.size();
        vector<long long> nums(v.begin(), v.end());
        for(int i = 0; i < n - 1; i++) {
            // cout << nums[i] << " ";
            // if(nums[i] < 0) return false;
            if(nums[i] > mid) return false;
            long long t = 1LL * mid - nums[i];
            nums[i] += t;
            nums[i + 1] -= t;
            // cout << nums[i + 1];
        }
        return nums.back() <= mid;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int mx = 0;
        for(auto x : nums) mx = max(mx, x);
        int lo = 0;
        int hi = mx;
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // cout << mid << endl;
            if(fun(mid, nums)) {
                // cout << mid << " ";
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
            // cout << endl;
        }
        return ans;

    }
};