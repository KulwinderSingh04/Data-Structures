class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mx = INT_MAX;
        for(int i = 0; i  < n - 1; i++) {
            mx = min(mx, nums[i + 1] - nums[i]);         
        }
        return mx;
    }
};