class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        unordered_map<long long, unordered_map<long long, long long>> mp;
        int n = capacity.size();
        long long sum = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            sum += capacity[i];
            if(mp[capacity[i]].find(sum - 2 * capacity[i]) != mp[capacity[i]].end()) {
                ans += mp[capacity[i]][sum - 2 * capacity[i]];
            }
            mp[capacity[i]][sum]++;
        }
        for(int i = 0; i < n - 1; i++) {
            if(capacity[i] == capacity[i + 1] && capacity[i] == 0) ans--;
        }
        return ans;
    }
};