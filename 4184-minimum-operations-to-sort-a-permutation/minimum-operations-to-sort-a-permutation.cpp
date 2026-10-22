class Solution {
public:
    int inc(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();
        int count = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) {
                count++;
                pivot = i;
            }
        }
        if(nums[0] < nums.back()) {
            count++;
            pivot = 0;    
        }
        if(count > 1) return -1;
        if(pivot == 0) return 0;
        return min(pivot, n - pivot + 2);
    }
    int dec(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();
        int count = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                count++;
                pivot = i;
            }
        }
        if(nums[0] > nums.back()) {
            count++;
            pivot = 0;    
        }
        if(count > 1) return -1;
        return min(pivot + 1, n - pivot + 1);
    }
    int minOperations(vector<int>& nums) {
        int a = inc(nums);
        // reverse(nums.begin(), nums.end());
        int b = dec(nums);
        if(a == -1) return b;
        if(b == -1) return a;
        return min(a, b);
    }
};