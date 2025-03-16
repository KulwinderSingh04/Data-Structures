class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        int ans = 0;
        int mx = INT_MIN;
        int count = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            if(nums[i] >= 0) count++;
            if(nums[i] < 0) continue;
            if(s.find(nums[i]) == s.end()) {
                ans += nums[i];
                s.insert(nums[i]);
            }
        }
        if(count == 0) return mx;
        return ans;
    }
};