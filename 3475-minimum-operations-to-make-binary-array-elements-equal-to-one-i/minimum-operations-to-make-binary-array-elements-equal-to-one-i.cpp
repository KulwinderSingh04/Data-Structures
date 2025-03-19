class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k = 3;
        int flipCount = 0;
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(i - k >= 0) {
                if(nums[i- k] == 2) flipCount--;
            }
            if((flipCount + nums[i]) % 2 == 0) {
                if(i + k > n) return -1;
                flipCount++;
                count++;
                nums[i] = 2;
            }
        }
        return count;
    }
};