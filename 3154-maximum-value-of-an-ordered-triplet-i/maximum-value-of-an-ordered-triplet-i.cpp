class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> leftMax(n), rightMax(n);
        for(int i = 1; i < n - 1; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }
        for(int i = n - 2; i >= 1; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i + 1]);
        }
        for(int i =1; i < n - 1; i++) 
            ans = max(ans,1LL * (leftMax[i] - nums[i]) * rightMax[i]);
        return ans;
    }
};