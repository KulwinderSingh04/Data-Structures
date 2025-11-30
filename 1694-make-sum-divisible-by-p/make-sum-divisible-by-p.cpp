class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for(auto x : nums) sum += x;
        // if(sum < p) return -1;
        long long mod = sum % p;
        if(mod == 0) return 0;
        int i = 0;
        unordered_map<long long, int> mp;
        long long s = 0;
        int ans = nums.size();
        mp[0] = -1;
        for(int i = 0; i < n; i++) {
            s += nums[i];
            s %= p;
            long long need = (s - mod + p) % p;
            if(mp.find(need) != mp.end()) {
                // cout << s << " " << i << " " << mp[s] << endl;
                ans = min(ans, i - mp[need]);
            }
            mp[s] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};