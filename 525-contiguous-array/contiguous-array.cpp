class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) nums[i] = -1;
        }
        unordered_map<int, int> m;
        m[0] = -1;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(m.find(sum) != m.end()) {
                ans = max(ans, i - m[sum]);
            }
            else m[sum] = i;
        }
        return ans;
    }
};