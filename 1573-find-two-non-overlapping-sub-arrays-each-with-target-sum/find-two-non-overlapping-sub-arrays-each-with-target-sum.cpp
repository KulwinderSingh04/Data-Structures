class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> vec(n, 1e9);
        unordered_map<int, int> mp;
        mp[0] = n;
        int sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            if(mp.find(sum - target) != mp.end()) {
                vec[i] = mp[sum - target] - i;
            }
            mp[sum] = i;
        }
        for(int i = n - 2; i >= 0; i--) {
            vec[i] = min(vec[i], vec[i + 1]);
        }
        unordered_map<int, int> mp2;
        int sum2 = 0;
        mp2[0] = -1;
        int ans = 1e9;
        for(int i = 0; i < n - 1; i++) {
            sum2 += arr[i];
            if(mp2.find(sum2 - target) != mp2.end()) {
                ans = min(ans, i - mp2[sum2 - target] + vec[i + 1]);
            }
            mp2[sum2] = i;
        }
        return ans == 1e9 ? -1 : ans;
    }
};