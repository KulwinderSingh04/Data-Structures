class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll ans = 0;
        int count = 0;
        int n = nums.size();
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            if((nums[i] ^ k) > nums[i]) {
                ans += (nums[i] ^ k);
                count++;
            } else {
                ans += nums[i];
            }
            mn = min(mn, abs(nums[i] - (nums[i] ^ k)));
        }
        if(count % 2 == 0) return ans;
        else return ans - mn;
    }
};