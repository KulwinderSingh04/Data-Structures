class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mn = INT_MAX;
        int mx = 0;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
            if(mx - mn > k) {
                count++;
                mn = mx = nums[i];
            }
        }
        return count + 1;
    }
};