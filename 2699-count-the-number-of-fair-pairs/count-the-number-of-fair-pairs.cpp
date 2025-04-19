class Solution {
public:
    long long fun(vector<int>& nums, int tar) {
        int i = 0;
        int n = nums.size();
        int j = n - 1;
        long long ans = 0;
        while(i < j) {
            if(nums[j] + nums[i] <= tar) {
                ans += j - i;
                i++;
            }
            else j--;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return fun(nums, upper) - fun(nums, lower - 1);
    }
};