class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<long long, long long> mp, freq;
        int sum = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            sum += nums[i];
            sum %= k;
            if(mp.find(sum) != mp.end()) {
                ans += mp[sum];
            }
            mp[sum]++;
        }
        cout << ans << " ";
        for(auto x : freq) {
            
            long long sum = 0;
            for(int i = 1; i <= x.second; i++) {
                sum += x.first;
                if(sum % k == 0) {
                    ans -= (x.second - i);
                }
            }
        }
        return ans;
    }
};