class Solution {
public:
    int fun(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int> mp;
        int ans = 0;
        while(j < n) {
            mp[nums[j]]++;
            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k - 1);
    }

};