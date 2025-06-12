class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int mxFreq = 0;
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        while(j < n) {
            mp[nums[j]]++;
            while(mp[nums[j]] > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};