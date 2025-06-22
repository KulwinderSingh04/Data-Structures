class Solution {
public:
    int helper(vector<int>& nums, int state) {
        int n = nums.size();
        int swaps = 0;
        int curr = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == state) {
                swaps += abs(i - curr);
                curr += 2;
            }
        }
        return swaps;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> even, odd;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2) odd.push_back(i);
            else even.push_back(i);
        }
        int e = even.size();
        int o = odd.size();
        if (abs(e - o) > 1) return -1;
        if(e > o) {
            return helper(nums, 0);
        } else if(o > e) {
            return helper(nums, 1);
        } else {
            return min(helper(nums, 0), helper(nums, 1));
        }
    }
};
