class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minKPos = -1, maxKPos = -1;
        int culpritIdx = -1;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == minK) minKPos = i;
            if(nums[i] == maxK) maxKPos = i;
            if(nums[i] > maxK || nums[i] < minK) culpritIdx = i;
            int smaller = min(minKPos, maxKPos);
            if(smaller - culpritIdx > 0) ans += smaller - culpritIdx;
        }
        return ans;
    }
};