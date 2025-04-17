class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int count = 0;
        while(i < n) {
            int j = i + 1;
            while(j < n) {
                if(nums[i] == nums[j] && (i * j) % k == 0) count++;
                j++;
            }
            i++;
        }
        return count;
    }
};