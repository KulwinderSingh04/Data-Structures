class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });
        long long ans = 0;
        int i = 0;
        int n = nums.size();
        int j = n - 1;
        while(i < j) {
            ans += 1LL * nums[i] * nums[i];
            ans -= 1LL * nums[j] * nums[j];
            i++;
            j--;
        }
        if(i == j) ans += 1LL * nums[i] * nums[i];
        return ans;
    }
};