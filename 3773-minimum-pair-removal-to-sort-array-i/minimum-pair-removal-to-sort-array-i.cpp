class Solution {
public:
    bool fun(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if(nums[i] < nums[i - 1])
            return false;
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;
        while (!fun(nums) && nums.size() > 1) {
            int mn = nums[0] + nums[1];
            int idx = 0;
            for (int i = 1; i < nums.size() - 1; ++i) {
                int sum = nums[i] + nums[i + 1];
                if (sum < mn) {
                    mn = sum;
                    idx = i;
                }
            }
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            op++;
        }
    
        return op;
    }
};