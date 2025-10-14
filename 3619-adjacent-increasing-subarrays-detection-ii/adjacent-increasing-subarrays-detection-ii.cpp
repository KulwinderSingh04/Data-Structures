class Solution {
public:
    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1;
        int a = 0;
        if(k == 1) return true;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) count++;
            else {
                if(count >= 2 * k) return true;
                if(count >= k) {
                    a++;
                    count = 1;
                    if(a == 2) return true;
                } else {
                    count = 1;
                    a = 0;
                }
            }
        }
        if(count >= 2 * k) return true;
        if(count >= k) {
            a++;
            count = 1;
            if(a == 2) return true;
        } else {
            count = 1;
            a = 0;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int lo = 1;
        int hi = n / 2;
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(check(nums, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};