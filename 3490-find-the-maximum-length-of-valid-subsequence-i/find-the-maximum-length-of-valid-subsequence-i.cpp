class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        // for(auto& x : nums) x %= 2;
        int p1 = 0, p2 = 1;
        int a1 = 0, a2 = 0, a3= 0, a4 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) a1++;
            else a2++;

            if(nums[i] % 2 == p2) {
                a4++;
                p2 = !p2;
            }

            if(nums[i] % 2 == p1) {
                a3++;
                p1 = !p1;
            }
        }
        return max(max(a1, a2), max(a3, a4));
    }
};