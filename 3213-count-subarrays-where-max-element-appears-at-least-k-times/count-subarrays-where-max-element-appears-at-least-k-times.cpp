class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = 0;
        for(auto ele : nums) mx = max(mx, ele);
        int i = 0;
        int j = 0;
        long long ans = 0;
        int count = 0;
        while(j < n) {
            if(nums[j] == mx) count++;
            while(count >= k) {
                ans += n - j;
                if(nums[i] == mx) count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};