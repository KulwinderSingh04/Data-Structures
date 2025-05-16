class Solution {
public:
    int fun(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0, sum = 0;
        while(j < n) {
            sum += nums[j] % 2;
            while(sum > goal) {
                sum -= nums[i] % 2;
                i++;
            }
            ans += j - i + 1;
            j++;
            
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k - 1);
    }
};