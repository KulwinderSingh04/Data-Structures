class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mx = 0, ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > mx) {
                mx = mp[nums[i]];
                ans = mx;
            } else if(mp[nums[i]] == mx) {
                ans += mx;
            }
        }
        return ans;
    }
};