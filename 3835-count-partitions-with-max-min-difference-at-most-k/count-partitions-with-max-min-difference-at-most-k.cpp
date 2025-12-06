class Solution {
public:
    int MOD = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1);
        dp[0] = 1;
        int l = 0;
        int r = 0;
        vector<long long> ps(n + 1);
        ps[0] = 1;
        multiset<int> mst;
        while(r < n) {
            mst.insert(nums[r]);
            while(*(prev(mst.end())) - *(mst.begin()) > k) {
                mst.erase(mst.find(nums[l]));
                l++;
            }
            if(l > 0) dp[r + 1] = ps[r] - ps[l - 1];
            else dp[r + 1] = ps[r];
            dp[r + 1] %= MOD;
            ps[r + 1] = ps[r] + dp[r + 1];
            r++;
        }
        return dp[n];
    }
};