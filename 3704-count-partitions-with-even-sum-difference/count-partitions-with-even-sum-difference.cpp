class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) sum +=nums[i];
        int s = 0;
        int count= 0;
        for(int i = 0; i < n - 1; i++) {
            s +=nums[i];
            sum -= nums[i];
            if((s - sum) % 2 == 0) count++;
        }
        return count;
    }
};