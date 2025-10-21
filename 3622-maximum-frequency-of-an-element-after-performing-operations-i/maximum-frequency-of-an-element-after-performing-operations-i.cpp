class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int mx = 0;
        for(int i = 0; i < n; i++) mx = max(mx, nums[i]);
        vector<int> freq(mx + 1);
        for(int i = 0; i < n; i++) freq[nums[i]]++;
        for(int i = 1; i < mx + 1; i++) {
            freq[i] += freq[i - 1];
            cout << freq[i] << " ";
        }
        int ans = 0;
        for(int i = 1; i < mx + 1; i++) {
            int l = max(1, i - k);
            int r = min(mx, i + k);
            int op =  (freq[r] - freq[l - 1]) - (freq[i] - freq[i - 1]);
            ans = max(ans, min(numOperations, op) + freq[i] - freq[i - 1]);
        }
        return ans;

    }
};