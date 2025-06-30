class Solution {
public:
    int binSearch(vector<int>& nums, int target) {
        int lo = 0;
        int n = nums.size();
        int hi = n - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target && (mid == n - 1 || nums[mid] != nums[mid + 1])) return mid;
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int idx = binSearch(nums, nums[i] + 1);
            if(idx != -1) {
                ans = max(ans, idx - i + 1);
            }
        }
        return ans;
    }
};