class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int ele = -1;
        int c1 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele) c1++;
            else if(c1 == 0) {
                ele = nums[i];
                c1 = 1;
            }
            else c1--;
        }
        int count = 0;
        int idx = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele) count++;
            if(count > (i + 1) / 2 && idx == -1) {
                idx = i;
                // one = count;
            }
        }
        if(count - ((idx + 1) / 2 + 1) >= (n - 1 - idx) / 2 + 1) return idx;
        return -1;
    }
};