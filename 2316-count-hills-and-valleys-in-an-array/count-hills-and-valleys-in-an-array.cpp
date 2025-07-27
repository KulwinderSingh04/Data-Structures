class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int l = 0;
        int ans=  0;
        while(nums[i] == nums[0]) i++;
        int r = i;
        while(r < n && nums[r] == nums[i]) r++;
        if(r == n) return 0;
        if(i == n) return 0;
        while(i < n) {
            if((nums[l] > nums[i] && nums[r] > nums[i]) || (nums[l] < nums[i] && nums[r] < nums[i])) {
                ans++;
            }
            l = i;
            i = r;
            while(r < n && nums[i] == nums[r]) r++;
            if(r == n) return ans;
        }
        return 0;
    }
};