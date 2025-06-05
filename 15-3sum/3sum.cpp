class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            // int num1 = nums[i];
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k]; 
                if(sum == 0) {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    ans.push_back(v);
                    j++;
                    k--;
                    while(j < n && nums[j] == nums[j - 1]) j++;
                    while(k > j && nums[k] == nums[k + 1]) k--;
                } 
                else if(sum > 0) k--;
                else j++;
            }
        }
        return ans;
    }
};