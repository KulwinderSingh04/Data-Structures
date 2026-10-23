class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int a = -1;
        for(int i = 0; i < n; i++) {
            if(i != nums[i]) a &= nums[i];
        }
        if(a == -1) return 0;
        return a;
    }
};