class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int> ());
        for(int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = i + 2;
            while(k < n) {
                if(nums[j] + nums[k] > nums[i]) return nums[i] + nums[j] + nums[k];
                k++;
                j++;
            }
        }
        return 0;

    }
};