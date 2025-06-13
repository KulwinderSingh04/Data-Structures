class Solution {
public:
    bool fun(int mid, int p, vector<int>& nums) {
        int a = 0;
        int i = 0;
        int n = nums.size();
        while(i < n - 1) {
            if(nums[i + 1] - nums[i] <= mid) {
                a++;
                i += 2;
            } else i++;
        }
        return a >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0;
        int hi = nums.back() - nums[0];
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(fun(mid, p, nums)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
};