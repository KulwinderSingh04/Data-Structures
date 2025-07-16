class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        for(auto& x : nums) x %= 2;
        int a1 = 0, a2 = 0, a3= 0, a4 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) a1++;
            else a2++;
        }
        int p = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == p) {
                a3++;
                p = !p;
            }
        }
        p = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == p) {
                a4++;
                p = !p;
            }
        }
        return max(max(a1, a2), max(a3, a4));
    }
};