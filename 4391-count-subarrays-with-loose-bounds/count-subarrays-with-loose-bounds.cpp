class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int prev = -1;
        long long a = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                long long left = i - prev;
                long long right = n - i;
                a += left * right;
                prev = i;
            }
        }
        return 1LL * n * (n + 1) / 2 - a;
    }
};