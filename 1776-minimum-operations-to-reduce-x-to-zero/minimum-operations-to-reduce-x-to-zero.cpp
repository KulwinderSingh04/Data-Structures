class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        vector<int> suff = nums;
        int ans = 1e9;
        if(suff[n - 1] == x) ans = 1;
        for(int i = n - 2; i >= 0; i--) {
            suff[i] += suff[i + 1];
            if(suff[i] == x) ans = n - i;
        }
        reverse(suff.begin(), suff.end());
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum == x) {
                ans = min(ans, i + 1);
                break;
            }
            if(sum > x) break;
            int idx = lower_bound(suff.begin(), suff.end(), x - sum) - suff.begin();
            if(idx != n) {
                if(suff[idx] == x - sum && i + 1 + idx + 1 <= n) ans = min(ans, i + 1 + idx + 1);
            }

        }
        return ans == 1e9 ? -1 : ans;
    }
};