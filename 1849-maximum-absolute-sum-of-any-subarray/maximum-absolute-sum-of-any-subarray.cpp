class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0, sum2 = 0;
        int mxAns = INT_MIN, mnAns = INT_MAX;
        for(int i = 0; i < n; i++) {
            sum1 += nums[i];
            sum2 += nums[i];
            mxAns = max(mxAns, sum1);
            mnAns = min(mnAns, sum2);
            if(sum1 < 0) sum1 = 0;
            if(sum2 > 0) sum2 = 0;
        }
        return max(abs(mxAns), abs(mnAns));
    }
};