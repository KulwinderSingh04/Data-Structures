class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            string a = to_string(nums[i]);
            int sum = 0;
            for(auto x : a) sum += (x - 48);
            // cout << sum << " ";
            if(sum == i) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};