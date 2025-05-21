class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int mid = 0;
        int hi = n - 1;
        while(mid <= hi) {
            if(nums[mid] == 2) {
                swap(nums[mid], nums[hi--]);
            } else if(nums[mid] == 0) {
                swap(nums[mid++], nums[lo++]);
            } else mid++;
        }
    }
};