class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0;
        int n = arr.size();
        vector<int> pref(1001);
        for(int j = 0; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(abs(arr[j] - arr[k]) > b) continue; 
                int r = min(1000, min(arr[j] + a, arr[k] + c));
                int l = max(0, max(arr[j] - a, arr[k] - c));
                if(l <= r) {
                    if(l != 0) ans += pref[r] - pref[l - 1];
                    else ans += pref[r];
                }
            }
            for(int idx = arr[j]; idx < 1001; idx++) pref[idx]++;
        }
        return ans;
    }
};