class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long sum = 0;
        unsigned long long pr = 1;
        int n = nums.size();
        int idx = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += nums[i];
        }
        long long currSum = sum;
        unsigned long long currPr = 1;
        // cout << idx << endl;
        int ans = -1;
        for(int i = n - 1; i >= 0; i--) {
            currSum -= nums[i];
            // cout << currSum << " " << currPr << endl;
            if(currSum == currPr) ans = i;
            if(currPr > 1e14 / nums[i]) break;
            currPr *= nums[i];
        }
        return ans;
    }
};