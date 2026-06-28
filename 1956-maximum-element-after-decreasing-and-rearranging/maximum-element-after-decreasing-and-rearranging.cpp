class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int val = 1;
        int ans = 1;
        arr[0] = 1;
        for(int i = 1; i < n; i++) {
            arr[i] = min(arr[i - 1] + 1, arr[i]);
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};