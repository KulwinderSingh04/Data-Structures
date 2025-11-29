class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a = accumulate(nums.begin(), nums.end(), 0);
        return a % k;
    }
};