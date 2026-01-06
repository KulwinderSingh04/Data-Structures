class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int n = arr.size();
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            sum %= 2;
            if(mp.find(1 - sum) != mp.end()) {
                ans += mp[1 - sum];
                ans %= MOD;
            }
            mp[sum]++;
        }
        return ans;
    }
};